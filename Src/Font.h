#pragma once
/**
* @file Font.h
*/
#include <GL/glew.h>
#include "BufferObject.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <vector>
#include <string>

namespace Font {
	struct Vertex;

	//フォント情報
	struct FontInfo {
		int id = -1; //文字コード
		glm::vec2 uv;//フォント画像の左上テクスチャ座標
		glm::vec2 size; //フォント画像のテクセルサイズ
		glm::vec2 offset;//表示位置をずらす距離
		float xadvance = 0;//カーソルをすすめる距離
	};

	/**
	* ビットマップフォント描画クラス
	*/
	class Renderer {
	public:
		Renderer() = default;
		~Renderer() = default;
		Renderer(const Renderer&) = delete;
		Renderer& operator = (const Renderer&) = delete;

		bool Init(size_t maxChar, const glm::vec2& ss);
		bool LoadFromFile(const char* filename);

		void Scale(const glm::vec2& s) { scale = s; }
		const glm::vec2& Scale() const { return scale; }
		void Color(const glm::vec4& c);
		glm::vec4 Color() const;

		void MapBuffer();
		bool AddString(const glm::vec2& position, const char* str);
		void UnmapBuffer();
		void Draw() const;

	private:
		BufferObject vbo;
		BufferObject ibo;
		VertexArrayObject vao;
		GLsizei vboCapacity = 0;
		std::vector<FontInfo> fontList;
		std::string texFilename;
		Shader::ProgramPtr progFont;
		glm::vec2 screenSize;
		glm::vec2 screenScale;

		glm::vec2 scale = glm::vec2(1, 1);
		glm::u8vec4 color = glm::u8vec4(255, 255, 255, 255);
		GLsizei vboSize = 0;
		Vertex* pVBO = nullptr;
	};
}