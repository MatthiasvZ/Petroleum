#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = 
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC) -Iinclude/gl
CFLAGS_DEBUG = $(CFLAGS) -Wall -Og -g -DDEBUG
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/libPetroleum.a

INC_RELEASE = $(INC) -Iinclude/gl
CFLAGS_RELEASE = $(CFLAGS) -O3 -Wall
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/libPetroleum.a

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/gl/Camera.o $(OBJDIR_DEBUG)/src/gl/Geometry.o $(OBJDIR_DEBUG)/src/gl/IndexBuffer.o $(OBJDIR_DEBUG)/src/gl/Renderer.o $(OBJDIR_DEBUG)/src/gl/Shader.o $(OBJDIR_DEBUG)/src/gl/Texture.o $(OBJDIR_DEBUG)/src/gl/VertexArray.o $(OBJDIR_DEBUG)/src/gl/VertexBuffer.o $(OBJDIR_DEBUG)/src/gl/Window.o $(OBJDIR_DEBUG)/src/other/Core.o $(OBJDIR_DEBUG)/src/other/ErrorFeedback.o $(OBJDIR_DEBUG)/src/other/FileManagement.o $(OBJDIR_DEBUG)/src/other/stb_image.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/gl/Camera.o $(OBJDIR_RELEASE)/src/gl/Geometry.o $(OBJDIR_RELEASE)/src/gl/IndexBuffer.o $(OBJDIR_RELEASE)/src/gl/Renderer.o $(OBJDIR_RELEASE)/src/gl/Shader.o $(OBJDIR_RELEASE)/src/gl/Texture.o $(OBJDIR_RELEASE)/src/gl/VertexArray.o $(OBJDIR_RELEASE)/src/gl/VertexBuffer.o $(OBJDIR_RELEASE)/src/gl/Window.o $(OBJDIR_RELEASE)/src/other/Core.o $(OBJDIR_RELEASE)/src/other/ErrorFeedback.o $(OBJDIR_RELEASE)/src/other/FileManagement.o $(OBJDIR_RELEASE)/src/other/stb_image.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src/gl || mkdir -p $(OBJDIR_DEBUG)/src/gl
	test -d $(OBJDIR_DEBUG)/src/other || mkdir -p $(OBJDIR_DEBUG)/src/other

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(AR) rcs $(OUT_DEBUG) $(OBJ_DEBUG)

$(OBJDIR_DEBUG)/src/gl/Camera.o: src/gl/Camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Camera.cpp -o $(OBJDIR_DEBUG)/src/gl/Camera.o

$(OBJDIR_DEBUG)/src/gl/Geometry.o: src/gl/Geometry.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Geometry.cpp -o $(OBJDIR_DEBUG)/src/gl/Geometry.o

$(OBJDIR_DEBUG)/src/gl/IndexBuffer.o: src/gl/IndexBuffer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/IndexBuffer.cpp -o $(OBJDIR_DEBUG)/src/gl/IndexBuffer.o

$(OBJDIR_DEBUG)/src/gl/Renderer.o: src/gl/Renderer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Renderer.cpp -o $(OBJDIR_DEBUG)/src/gl/Renderer.o

$(OBJDIR_DEBUG)/src/gl/Shader.o: src/gl/Shader.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Shader.cpp -o $(OBJDIR_DEBUG)/src/gl/Shader.o

$(OBJDIR_DEBUG)/src/gl/Texture.o: src/gl/Texture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Texture.cpp -o $(OBJDIR_DEBUG)/src/gl/Texture.o

$(OBJDIR_DEBUG)/src/gl/VertexArray.o: src/gl/VertexArray.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/VertexArray.cpp -o $(OBJDIR_DEBUG)/src/gl/VertexArray.o

$(OBJDIR_DEBUG)/src/gl/VertexBuffer.o: src/gl/VertexBuffer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/VertexBuffer.cpp -o $(OBJDIR_DEBUG)/src/gl/VertexBuffer.o

$(OBJDIR_DEBUG)/src/gl/Window.o: src/gl/Window.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gl/Window.cpp -o $(OBJDIR_DEBUG)/src/gl/Window.o

$(OBJDIR_DEBUG)/src/other/Core.o: src/other/Core.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/other/Core.cpp -o $(OBJDIR_DEBUG)/src/other/Core.o

$(OBJDIR_DEBUG)/src/other/ErrorFeedback.o: src/other/ErrorFeedback.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/other/ErrorFeedback.cpp -o $(OBJDIR_DEBUG)/src/other/ErrorFeedback.o

$(OBJDIR_DEBUG)/src/other/FileManagement.o: src/other/FileManagement.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/other/FileManagement.cpp -o $(OBJDIR_DEBUG)/src/other/FileManagement.o

$(OBJDIR_DEBUG)/src/other/stb_image.o: src/other/stb_image.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/other/stb_image.cpp -o $(OBJDIR_DEBUG)/src/other/stb_image.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src/gl
	rm -rf $(OBJDIR_DEBUG)/src/other

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src/gl || mkdir -p $(OBJDIR_RELEASE)/src/gl
	test -d $(OBJDIR_RELEASE)/src/other || mkdir -p $(OBJDIR_RELEASE)/src/other

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(AR) rcs $(OUT_RELEASE) $(OBJ_RELEASE)

$(OBJDIR_RELEASE)/src/gl/Camera.o: src/gl/Camera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Camera.cpp -o $(OBJDIR_RELEASE)/src/gl/Camera.o

$(OBJDIR_RELEASE)/src/gl/Geometry.o: src/gl/Geometry.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Geometry.cpp -o $(OBJDIR_RELEASE)/src/gl/Geometry.o

$(OBJDIR_RELEASE)/src/gl/IndexBuffer.o: src/gl/IndexBuffer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/IndexBuffer.cpp -o $(OBJDIR_RELEASE)/src/gl/IndexBuffer.o

$(OBJDIR_RELEASE)/src/gl/Renderer.o: src/gl/Renderer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Renderer.cpp -o $(OBJDIR_RELEASE)/src/gl/Renderer.o

$(OBJDIR_RELEASE)/src/gl/Shader.o: src/gl/Shader.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Shader.cpp -o $(OBJDIR_RELEASE)/src/gl/Shader.o

$(OBJDIR_RELEASE)/src/gl/Texture.o: src/gl/Texture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Texture.cpp -o $(OBJDIR_RELEASE)/src/gl/Texture.o

$(OBJDIR_RELEASE)/src/gl/VertexArray.o: src/gl/VertexArray.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/VertexArray.cpp -o $(OBJDIR_RELEASE)/src/gl/VertexArray.o

$(OBJDIR_RELEASE)/src/gl/VertexBuffer.o: src/gl/VertexBuffer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/VertexBuffer.cpp -o $(OBJDIR_RELEASE)/src/gl/VertexBuffer.o

$(OBJDIR_RELEASE)/src/gl/Window.o: src/gl/Window.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gl/Window.cpp -o $(OBJDIR_RELEASE)/src/gl/Window.o

$(OBJDIR_RELEASE)/src/other/Core.o: src/other/Core.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/other/Core.cpp -o $(OBJDIR_RELEASE)/src/other/Core.o

$(OBJDIR_RELEASE)/src/other/ErrorFeedback.o: src/other/ErrorFeedback.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/other/ErrorFeedback.cpp -o $(OBJDIR_RELEASE)/src/other/ErrorFeedback.o

$(OBJDIR_RELEASE)/src/other/FileManagement.o: src/other/FileManagement.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/other/FileManagement.cpp -o $(OBJDIR_RELEASE)/src/other/FileManagement.o

$(OBJDIR_RELEASE)/src/other/stb_image.o: src/other/stb_image.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/other/stb_image.cpp -o $(OBJDIR_RELEASE)/src/other/stb_image.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src/gl
	rm -rf $(OBJDIR_RELEASE)/src/other

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

