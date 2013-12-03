#ifndef TEXT_H
#define TEXT_H

#include "shader.hpp"
#include "vao.hpp"


class Text {
	public:
		Text();
		Text(Text const &t);
		Text(ShaderProgram p, std::string str, float x, float y);
		Text(ShaderProgram p, std::string str, float x, float y, float size);
		Text &operator=(Text const &t);

		void setStr(std::string str);
		void draw();
	private:
		void genBuffers();

		ShaderProgram p;

		std::string str;
		float x;
		float y;
		float size;

		Texture t;
		Buffer vertices;
		Buffer uvs;
};

#endif