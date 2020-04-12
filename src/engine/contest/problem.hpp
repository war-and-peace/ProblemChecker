namespace engine {
namespace contest {
class Problem {
   private:
    std::string test_folder_path;
    double max_execution_time {1.0};
    bool isInteractive {false};

   public:

    Problem(std::string_view test_folder_path) : test_folder_path(test_folder_path){};
    
   protected:
};
}  // namespace contest
}  // namespace engine