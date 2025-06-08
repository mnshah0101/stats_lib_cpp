#pragma once

/*
Lets plan what functions we need
first is definite pdf functions
*/
namespace stats
{
    namespace distributions
    {

        constexpr double normal_pdf(double x, double mean, double std);

        constexpr double normal_cdf(double x, double mean, double std);
    }}
