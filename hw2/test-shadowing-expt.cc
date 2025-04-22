#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/propagation-module.h"
#include "ns3/wifi-module.h"
#include "ns3/log-normal-shadowing-propagation-loss-model.h"
#include <fstream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("TestShadowingExperiment");

void RunSimulation(double distance, double exponent, double variance, std::ofstream &outputFile)
{
    // Create two nodes
    NodeContainer nodes;
    nodes.Create(2);

    // Set up mobility
    Ptr<MobilityModel> mobilityA = CreateObject<ConstantPositionMobilityModel>();
    Ptr<MobilityModel> mobilityB = CreateObject<ConstantPositionMobilityModel>();
    nodes.Get(0)->AggregateObject(mobilityA);
    nodes.Get(1)->AggregateObject(mobilityB);
    
    mobilityA->SetPosition(Vector(0.0, 0.0, 0.0));
    mobilityB->SetPosition(Vector(distance, 0.0, 0.0));

    // Create propagation model
    Ptr<LogNormalShadowingPropagationLossModel> model = CreateObject<LogNormalShadowingPropagationLossModel>();
    model->SetAttribute("Exponent", DoubleValue(exponent));
    model->SetAttribute("ShadowingStdDev", DoubleValue(variance));

    // Compute received power
    double rxPowerDbm = model->CalcRxPower(0.0, mobilityA, mobilityB);

    // Log output
    NS_LOG_INFO("Distance: " << distance << "m, Exponent: " << exponent
               << ", Variance: " << variance << ", Rx Power: " << rxPowerDbm << " dBm");

    outputFile << distance << " " << rxPowerDbm << std::endl;
}

int main(int argc, char *argv[])
{
    LogComponentEnable("TestShadowingExperiment", LOG_LEVEL_INFO);

    std::ofstream outputFile("shadowing_results.dat");

    // Run simulations for different distances and exponents
    for (double distance = 200; distance <= 5000; distance += 100)
    {
        RunSimulation(distance, 3.0, 1.0, outputFile);  // LP Scenario
    }
    
    outputFile.close();
    return 0;
}
