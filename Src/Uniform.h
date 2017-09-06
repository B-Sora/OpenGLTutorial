#pragma once

/**
* @file Uniform.h
*/
#include <glm/glm.hpp>

namespace Uniform {

	//頂点シェーダのパラメーター型
	struct  VertexData
	{
		glm::mat4 matMVP;
		glm::mat4 matModel;
		glm::mat3x4 matNormal;
		//glm::vec4 lightPosition;
		//glm::vec4 lightColor;
		//glm::vec4 ambientColor;
	};

	/**
	* ライトデータ（点光源）
	*/
	struct PointLight {
		glm::vec4 position; //座標（ワールド座標系）
		glm::vec4 color; //明るさ

	};

	const int maxLightCount = 4; //ライトの数

	/**
	* ライティングパラメーター
	*/
	struct LightData {
		glm::vec4 ambientColor; //環境光
		PointLight light[maxLightCount]; //ライトのリスト
	};

	/**
	* ポストエフェクトデータ
	*/
	struct PostEffectData {
		glm::mat4x4 matColor;
	};

}