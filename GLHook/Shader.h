#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // ����glad����ȡ���еı���OpenGLͷ�ļ�

class Shader
{
public:
	// ����ID
	unsigned int ID;

	// ��������ȡ��������ɫ��
	void Init(const GLchar * vShaderCode, const GLchar * fShaderCode);
	// ʹ��/�������
	void use();
	// uniform���ߺ���
	void setBool(const char *name, bool value) const;
	void setInt(const char *name, int value) const;
	void setFloat(const char *name, float value) const;
};

#endif
