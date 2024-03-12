#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"

//std
#include<memory>
#include<vector>

namespace lve{
	class FirstApp 
	{
		public:
			static constexpr int WIDTH = 800; 
			static constexpr int HEIGHT = 600;

			FirstApp();
			~FirstApp();

			FirstApp(int w, int h, std::string name);
			FirstApp& operator=(const LveWindow&) = delete;



			void run();

		private:

			void sierpinski(std::vector<LveModel::Vertex>& vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);
			void loadModels();
			void createPipelineLayout();
			void createPipeline();
			void createCommandBuffers();
			void drawFrame();

			LveWindow lveWindow{ WIDTH, HEIGHT, "Hi vulkan!" };
			LveDevice lveDevice{lveWindow};
			LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtend()};
			std::unique_ptr<LvePipeline> lvePipeline;
			VkPipelineLayout pipelineLayout;
			std::vector<VkCommandBuffer> commandBuffers;
			std::unique_ptr<LveModel> lveModel;


	};
}