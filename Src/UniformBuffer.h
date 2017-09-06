#pragma once

/**
* @file UniformBuffer.h
*/
#include <GL/glew.h>
#include <string>
#include <memory>

class UniformBuffer;
typedef std::shared_ptr<UniformBuffer> UniformBufferPtr; //UBOポインタ型

/**
* UBOクラス
*/
class UniformBuffer {
public:
	static UniformBufferPtr Create(
		GLsizeiptr size, GLuint bindingPoint, const char* name);
	bool BufferSubData(const GLvoid* data, GLintptr offset = 0, GLsizeiptr size = 0);
	GLsizeiptr Size() const { return size; }

	void BindBufferRange(GLintptr offset, GLsizeiptr size) const;
	void* MapBuffer() const;
	void UnmapBuffer() const;

private:
	UniformBuffer() = default;
	~UniformBuffer();
	UniformBuffer(const UniformBuffer&) = delete;
	UniformBuffer& operator = (const UniformBuffer&) = delete;

private:
	GLuint ubo = 0; //Uniform Buffer Object
	GLsizeiptr size = 0; //UBO のバイトサイズ
	GLuint bindingPoint; //UBO の割当て先バインディング・ポイント
	std::string name; //UBO名
};