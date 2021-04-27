#include "puzzle.h"
#include "solver.h"
<<<<<<< HEAD
#include "logger.h"
=======
>>>>>>> 49ba70431d9004db7490913cd93a6733624ef49b

#include <iostream>
#include <fstream>
#include <vector>
<<<<<<< HEAD
#include <sstream>
#include <thread>
#include <algorithm>  // std::sort
#include <mutex>

int main(int argc, char* argv[]) {

    std::string par1 = std::string(argv[1]);
    
    int NUM_THREADS;
    NUM_THREADS = std::stoi(par1);

=======

#include <algorithm>  // std::sort

int main(int argc, char* argv[]) {

>>>>>>> 49ba70431d9004db7490913cd93a6733624ef49b
    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }
<<<<<<< HEAD
    
    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    
    // ----- All data loaded -----
    
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;
    
    std::vector<std::thread*> threads;
    std::mutex m;
    
    int puzzles_size=puzzles.size();
    const int puzzlesPerThread = 1;
    int first = 0;
    int last = puzzlesPerThread - 1;
    
    
    for(int i=0; i<NUM_THREADS; ++i){
        if(i==puzzles.size())
            break;
        if(i == (NUM_THREADS -1))
            last = puzzles_size - 1;
        
        threads.push_back(new std::thread{ [&, first, last] 
        {
            for (int j = first; j<=last; j++) {
                if (j>=puzzles.size())
                    break;
                Puzzle& puzzle = puzzles.at(j);
                Solver solver{puzzle};
                for (std::string word : puzzle ) {
                    Solution S = solver.solve(word);
                    m.lock();
                    solutions.push_back(S);
                    m.unlock();
                  }
        }
        }   
   } );
   }
    for(std::thread* t : threads) {
        t->join();
=======

    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    // ----- All data loaded -----
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;

    // Loop through all of the loaded puzzles
    for(Puzzle& puzzle : puzzles) {

        // Find each word in the current puzzle
        for(std::string word : puzzle) {
        
            // Instance a Solver, and use it to solve for the word
            Solver solver{puzzle};
            Solution s = solver.solve(word);
            solutions.push_back(s);
            cout << endl;
        }
>>>>>>> 49ba70431d9004db7490913cd93a6733624ef49b
    }
    
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
    
