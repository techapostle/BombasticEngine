// src/RenderingEngineTest.cpp
// Author: Kian Dadkhah

#include <gtest/gtest.h>
#include "RenderingEngine.h"

namespace BombasticEngine {
  // Test fixture for RenderingEngine class.
  class RenderingEngineTest : public ::testing::Test {
    protected:
      RenderingEngine* engine;

      // This method is called before each test is run.
      void SetUp() override {
        engine = new RenderingEngine(800, 600);
      }
      
      // This method is called after each test is run.
      void TearDown() override {
        // Free the memory allocated for the engine.
        delete engine;
      }
  };

  // Test case: Check if the engine initializes without errors.
  TEST_F(RenderingEngineTest, InitializesWithoutErrors) {
    // Since we can't directly access private members, we might need to add some public methods
    // in the RenderingEngine class to retrieve the status of 'window' and 'renderer' for testing purposes.
    // Alternatively, we can make RenderingEngineTest a friend class of RenderingEngine.

    // Check if the engine is initialized successfully.
    EXPECT_TRUE(engine->isValid());
  }

  // TODO: Add more test cases here.

} // namespace BombasticEngine

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
