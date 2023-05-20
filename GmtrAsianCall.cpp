#include "GmtrAsianCall.h"
#include "EurCall.h"
#include <cmath>
//using namespace std;
namespace fre {
 
     double N_gauss(double x)
    {
        double gamma = 0.2316419;     double a1 = 0.319381530;
        double a2 = -0.356563782;   double a3 = 1.781477937;
        double a4 = -1.821255978;   double a5 = 1.330274429;
        double pi = 4.0 * atan(1.0); double k = 1.0 / (1.0 + gamma * x);
        if (x >= 0.0)
        {
            return 1.0 - ((((a5 * k + a4) * k + a3) * k + a2) * k + a1) * k * exp(-x * x / 2.0) / sqrt(2.0 * pi);
        }
        else return 1.0 - N_gauss(-x);
    }
 
    double GmtrAsianCall::Payoff(const SamplePath& S) const
    {
        double Prod = 1.0;
        for (int i = 0; i < m; i++)
        {
            Prod = Prod * S[i];
        }
        if (pow(Prod, 1.0 / m) < K) return 0.0;
        return pow(Prod, 1.0 / m) - K;
    }

    double GmtrAsianCall::PriceByBSFormula(const MCModel& Model)
    {
        double a = exp(-Model.GetR() * T) * Model.GetS0() * exp((m + 1.0) * T / (2.0 * m) * (Model.GetR() + Model.GetSigma() * Model.GetSigma() * ((2.0 * m + 1.0) / (3.0 * m) - 1.0) / 2.0));
        double b = Model.GetSigma() * sqrt((m + 1.0) * (2.0 * m + 1.0) / (6.0 * m * m));
        EurCall G(T, K);
        Price = G.PriceByBSFormula(a, b, Model.GetR());
        return Price;
    }
    
    double GmtrAsianCall::DeltaByBSFormula(const MCModel& Model)
    {
        double a = exp(-Model.GetR() * T) * Model.GetS0() * exp((m + 1.0) * T / (2.0 * m) * (Model.GetR() + Model.GetSigma() * Model.GetSigma() * ((2.0 * m + 1.0) / (3.0 * m) - 1.0) / 2.0));
        double b = Model.GetSigma() * sqrt((m + 1.0) * (2.0 * m + 1.0) / (6.0 * m * m));
        double d_delta_plus = ((log(a/K) + (Model.GetR() + 0.5 * pow(b,2))* T) / (b * sqrt(T)));
        double BS_delta = N_gauss(d_delta_plus);
        //cout<< "BS_delta: "<<BS_delta<<endl;
        return BS_delta;
    }
}
