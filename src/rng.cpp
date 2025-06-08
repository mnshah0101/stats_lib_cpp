#define _USE_MATH_DEFINES

#include <random>
#include <iostream>
#include <ctime>
#include <exception>


namespace stats {
    class RNG {
        private:
        std::mt19937 rng;

        public:
        RNG() {
            rng = std::mt19937(std::time(0));

        }

        double uniform(double a, double b){
            if (a > b){
                throw std::runtime_error("A must be less than b");
            }
            auto normal = rng() / (double)(std::mt19937::max());

            




            return normal * (b-a) + a;
            
        }

        int uniform_int(int a, int b){
            return (int)uniform(a,b);
        }
        

        double bernoulli(double p){
            auto val = uniform(0,1);
            return val < p;


        }

        double normal(double mu, double sigma){
            auto u1 = uniform(0,1);
            auto u2 = uniform(0, 1);

            return std::sqrt(-2*std::log(u1)) * std::cos(2 * M_PI * u2);

        };


        double exponential(double lambda){
            auto u = uniform(0,1);
            return -1 * std::log(1-u) / lambda;
        }

        int bernouli(int n, double p){

            int total = 0;

            for(int i = 0; i < n; i++){
                total +=  uniform(0,1) < p;

            };

            return total;
        };

        int poisson(double lambda){
            //since poisson represents the number of events that occur if we wait for lambda minutes, then if we get a bunch of exponential - times between events are independent exponentials

            double total = 0;

            int return_val = 0;


            while (total < lambda){
                total += exponential(lambda);
                if(total >= lambda){
                    return return_val;
                }
                return_val += 1;
            }



            
        }

        

    
    };


}





int main(){

    auto rng = stats::RNG();
    for(int i = 0; i < 100; i++){
        std::cout << rng.poisson(0.5) << '\n';
    }

    return 0;
}
