#include "Shader.h"
#include<assert.h>

void Shader::Init(const GLchar * vShaderCode, const GLchar * fShaderCode)
{
	// 2. ������ɫ��
	unsigned int vertex, fragment;
	int success;

	// ������ɫ��
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// ��ӡ�����������еĻ���
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	assert(success);
	// ������ɫ��
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// ��ӡ�����������еĻ���
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	assert(success);
	// ��ɫ������
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	// ��ӡ���Ӵ�������еĻ���
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	assert(success);

	// ɾ����ɫ���������Ѿ����ӵ����ǵĳ������ˣ��Ѿ�������Ҫ��
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const char* name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

void Shader::setInt(const char * name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::setFloat(const char * name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name), value);
}
