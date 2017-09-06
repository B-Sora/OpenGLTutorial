/**
* @file BufferObject.cpp
*/
#include "BufferObject.h"

/**
* �o�b�t�@�I�u�W�F�N�g���쐬����
* 
* @param target 
* @param size   
* @param data   
* @param usage  
*/
void BufferObject::Init(
	GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) {
	Destroy();
	glGenBuffers(1, &id);
	glBindBuffer(target, id);
	glBufferData(target, size, data, usage);
	glBindBuffer(target, 0);
}

/**
* Buffer Object��j������
*/
void BufferObject::Destroy() {
	if (id) {
		glDeleteBuffers(1, &id);
		id = 0;
	}
}

/**
* VAO���쐬����
* 
* @param vbo ���_�o�b�t�@�I�u�W�F�N�g��ID
* @param ibo �C���f�b�N�X�o�b�t�@�I�u�W�F�N�g��ID
*/
void VertexArrayObject::Init(GLuint vbo, GLuint ibo)
{
	Destroy();
	glGenVertexArrays(1, &id);
	glBindVertexArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBindVertexArray(0);
}

/*
* VAO��j������
*/
void VertexArrayObject::Destroy()
{
	if (id) {
		glDeleteVertexArrays(1, &id);
		id = 0;
	}
}

/**
* ���_�A�g���r���[��ݒ肷��
* 
* 
* 
* 
* 
* 
* 
*/
void VertexArrayObject::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, size_t offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, type, normalized, stride,
		reinterpret_cast<GLvoid*>(offset));
}

/**
* VAO�������Ώۂɂ���
*/
void VertexArrayObject::Bind() const
{
	glBindVertexArray(id);
}

/**
* VAO�������Ώۂ���O��
*/
void VertexArrayObject::Unbind() const
{
	glBindVertexArray(0);
}
