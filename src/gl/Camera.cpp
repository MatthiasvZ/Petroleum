#include "../../Petroleum.h"
#include <glm/gtc/matrix_transform.hpp>

namespace PT
{

Camera::Camera(float x, float y, float z)
    : clippingDistance(100.0f), movFacH(15.0f), movFacV(15.0f), turnSpeed(0.35f), pitch(0.0f), yaw(-90.0f), sprinting(false), camPos(glm::vec3(x, y, z)), camFront(glm::vec3(0.0f, 0.0f, 0.0f)), initX(x), initY(y), initZ(z)
{

}

glm::mat4 Camera::update(float deltaTime, Input inputs)
{
    float movSpeedH = movFacH * deltaTime;
    float movSpeedV = movFacV * deltaTime;

    if (inputs.ctrlHeld)
        sprinting = true;
    else
        sprinting = false;

    if (inputs.wHeld)
        camPos += movSpeedH * (sprinting + 1) * camFront;
    if (inputs.sHeld)
        camPos -= movSpeedH * (sprinting + 1) * camFront;
    if (inputs.aHeld)
        camPos -= movSpeedH * (sprinting + 1) * glm::normalize(glm::cross(camFront, glm::vec3(0.0f, 1.0f, 0.0f)));
    if (inputs.dHeld)
        camPos += movSpeedH * (sprinting + 1) * glm::normalize(glm::cross(camFront, glm::vec3(0.0f, 1.0f, 0.0f)));
    if (inputs.spaceHeld)
        camPos.y += movSpeedV * (sprinting + 1);
    if (inputs.leftShiftHeld)
        camPos.y -= movSpeedV * (sprinting + 1);

    if (inputs.kp5Held && !inputs.ctrlHeld)
    {
        yaw = -90.0f;
        pitch = 0.0f;
    }
    if (inputs.kp5Held && inputs.ctrlHeld)
    {
        camPos.x = 1.0f;
        camPos.y = 1.0f;
        camPos.z = 1.0f;
    }


    yaw += (inputs.mouseX - lastMouseX) * turnSpeed;
    pitch += (lastMouseY - inputs.mouseY) * turnSpeed;
    if (pitch > 89.99f)
        pitch = 89.99f;
    if (pitch < -89.99f)
        pitch = -89.99f;

    camFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    camFront.y = sin(glm::radians(pitch));
    camFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    lastMouseX = inputs.mouseX;
    lastMouseY = inputs.mouseY;


    float vp[4];
    PTGLEC(glGetFloatv(GL_VIEWPORT, vp));

    glm::mat4 projMat = glm::perspective(glm::radians(90.0f), vp[2] / vp[3], 1.0f, clippingDistance);

    glm::mat4 viewMat = glm::mat4(glm::lookAt(
            camPos,
            camPos + camFront,
            glm::vec3(0.0f, 1.0f, 0.0f))
    );
    return projMat * viewMat;
}

}
