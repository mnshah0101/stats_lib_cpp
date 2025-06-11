#define _USE_MATH_DEFINES

#include "stats_lib/stats_lib/estimation.hpp"
#include <random>
#include <iostream>
#include <ctime>
#include <exception>
#include <stdexcept>


namespace stats {
    namespace estimation{
        std::pair<double, double> mleNormal(const std::vector<double>& data){
            auto mu_hat = 0.0;
            for (auto& x : data){
                mu_hat += x;
            }

            mu_hat /= data.size();

            auto sigma_hat = 0.0;
            for (auto& x : data){
                sigma_hat += (x - mu_hat) * (x - mu_hat);
            }
            sigma_hat /= data.size();

            return std::make_pair(mu_hat, sigma_hat);

        }


        double mleExponential(const std::vector<double>& data){
            auto lambda_hat = 0.0;
            for (auto& x : data){
                lambda_hat += x;
            }

            lambda_hat /= data.size();

            return 1.0 / lambda_hat;
        }

        double mleBernoulli(const std::vector<double>& data){
            auto p_hat = 0.0;
            for (auto& x : data){
                p_hat += x;
            }

            p_hat /= data.size();

            return p_hat;
        }

        std::pair<double, double> mleBeta(const std::vector<double>& data){
            auto alpha_hat = 0.0;
            auto beta_hat = 0.0;
            for (auto& x : data){
                alpha_hat += x;
                beta_hat += 1.0 - x;
            }

            return std::make_pair(alpha_hat, beta_hat);
        }


        //methods of moments estimator
        std::pair<double, double> momNormal(const std::vector<double>& data){
            auto mu_hat = 0.0;
            for (auto& x : data){
                mu_hat += x;
            }

            mu_hat /= data.size();

            auto sigma_hat = 0.0;
            for (auto& x : data){
                sigma_hat += (x - mu_hat) * (x - mu_hat);
            }
            sigma_hat /= data.size();

            return std::make_pair(mu_hat, sigma_hat);
        }

        double momExponential(const std::vector<double>& data){
            auto lambda_hat = 0.0;
            for (auto& x : data){
                lambda_hat += x;
            }

            lambda_hat /= data.size();

            return 1.0 / lambda_hat;
        }

        double momBernoulli(const std::vector<double>& data){
            auto p_hat = 0.0;
            for (auto& x : data){
                p_hat += x;
            }

            p_hat /= data.size();

            return p_hat;
        }


        double momPoisson(const std::vector<double>& data){
            auto lambda_hat = 0.0;
            for (auto& x : data){
                lambda_hat += x;
            }

            lambda_hat /= data.size();

            return lambda_hat;
        }

        std::vector<double> mleGeneric(
            const std::function<double(const std::vector<double>&)>& logLikelihood,
            const std::vector<double>& data,
            const std::vector<double>& initial_guesses,
            const double& tolerance,
            const int& max_iterations
        ){

            auto current_guesses = initial_guesses;
            auto current_log_likelihood = logLikelihood(current_guesses);

            for (int i = 0; i < max_iterations; i++){
                auto next_guesses = current_guesses;
                auto next_log_likelihood = current_log_likelihood;

                for (int j = 0; j < current_guesses.size(); j++){
                    auto current_guess = current_guesses[j];
                    auto current_guess_log_likelihood = logLikelihood(current_guesses);

                    auto new_guess = current_guess + 1.0;
                    auto new_guess_log_likelihood = logLikelihood(new_guess);

                    if (new_guess_log_likelihood > current_guess_log_likelihood){
                        next_guesses[j] = new_guess;
                        next_log_likelihood = new_guess_log_likelihood;
                    }

                    new_guess = current_guess - 1.0;
                    new_guess_log_likelihood = logLikelihood(new_guess);

                    if (new_guess_log_likelihood > current_guess_log_likelihood){
                        next_guesses[j] = new_guess;
                        next_log_likelihood = new_guess_log_likelihood;
                    }

                }

                if (std::abs(next_log_likelihood - current_log_likelihood) < tolerance){
                    return next_guesses;
                }

                current_guesses = next_guesses;
                current_log_likelihood = next_log_likelihood;
            }

            throw std::runtime_error("Maximum iterations reached without convergence");



        }








    }
}
