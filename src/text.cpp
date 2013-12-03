#include "text.hpp"

#include <glm/gtc/matrix_transform.hpp>


Text::Text() {
}

Text::Text(Text const &t) : p(t.p), str(t.str), x(t.x), y(t.y), vertices(t.vertices), uvs(t.uvs) {
}

Text::Text(ShaderProgram p, std::string str, float x, float y) : Text(p, str, x, y, 12.0f) {
}

Text::Text(ShaderProgram p, std::string str, float x, float y, float size) : p(p), str(str), x(x), y(y), size(size) {
	genBuffers();
}

void Text::setStr(std::string str) {
	this->str = str;
	genBuffers();
}

void Text::draw() {
	vertices.setAttrib(this->p, "vertexPosition",  3, GL_FLOAT, false);
	uvs.setAttrib(this->p, "vertexUV", 2, GL_FLOAT, false);
	this->vertices.drawArrays();
}

void Text::genBuffers() {
	std::vector<glm::vec3> verts;
	std::vector<glm::vec2> temp_uvs;

	for(unsigned i = 0; i < this->str.length(); ++i) {
		glm::vec3 vertex_up_left    = glm::vec3(x + i * size       , y + size * 10.0f / 6.0f, 0.0f);
	    glm::vec3 vertex_up_right   = glm::vec3(x + i * size + size, y + size * 10.0f / 6.0f, 0.0f);
	    glm::vec3 vertex_down_right = glm::vec3(x + i * size + size, y                      , 0.0f);
	    glm::vec3 vertex_down_left  = glm::vec3(x + i * size       , y                      , 0.0f);

	    verts.push_back(vertex_up_left);
	    verts.push_back(vertex_up_right);
	    verts.push_back(vertex_down_right);
	 
	    verts.push_back(vertex_down_right);
	    verts.push_back(vertex_down_left);
	    verts.push_back(vertex_up_left);

	    float uv_x = 0;
	    float uv_y = 0;

	    char c = str[i];
	    if(c >= 'a' && c <= 'z') {
			uv_x = (c - 'a') * 6 / 168.0f;
			uv_y = 0 / 3.0f;
		}
		else if(c >= 'A' && c <= 'Z') {
			uv_x = (c - 'A') * 6 / 168.0f;
			uv_y = 1 / 3.0f;
		}
		else if(c >= '0' && c <= '9') {
			uv_x = (c - '0') * 6 / 168.0f;
			uv_y = 2 / 3.0f;
		}
		else if(c == '-') {
			uv_x = 102.0f / 168.0f;
			uv_y = 2 / 3.0f;
		}
		else {
			uv_x = 27.0f / 28.0f;
			uv_y = 0 / 3.0f;
		}

		glm::vec2 uv_down_left    = glm::vec2(uv_x               , 1.0f - uv_y);
		glm::vec2 uv_down_right   = glm::vec2(uv_x + 1.0f / 28.0f, 1.0f - uv_y);
		glm::vec2 uv_up_right = glm::vec2(uv_x + 1.0f / 28.0f, 1.0f - (uv_y + 1.0f / 3.0f));
		glm::vec2 uv_up_left  = glm::vec2(uv_x               , 1.0f - (uv_y + 1.0f / 3.0f));

		temp_uvs.push_back(uv_up_left);
		temp_uvs.push_back(uv_up_right);
		temp_uvs.push_back(uv_down_right);

		temp_uvs.push_back(uv_down_right);
		temp_uvs.push_back(uv_down_left);
		temp_uvs.push_back(uv_up_left);
	}

	vertices = Buffer(verts);
	uvs = Buffer(temp_uvs);
}

Text &Text::operator=(Text const &t) {
	p = t.p;
	str = t.str;
	x = t.x;
	y = t.y;
	vertices = t.vertices;
	uvs = t.uvs;

	return *this;
}