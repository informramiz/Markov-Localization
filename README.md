# Markov-Localization (Bayesian Filter)

Localize a vehicle in a given map and sensors data, using Markov Localization. This code follows a very simple form of 1D Markov Localization.


## Getting Started

```
//declare map:
Map map_1d;

//declare measurement list:
std::vector<MeasurementPackage> measurement_pack_list;

//declare helpers:
HelpFunctions helper;

//read map:
helper.ReadMapData("data/map_1d.txt", map_1d);

//read in data to measurement package list:
helper.ReadMeasurementData("data/example03/control_data.txt",
"data/example03/observations/",
measurement_pack_list);

//create instance of 1d_bayesian localization filter:
BayesianFilter localization_1d_bayesian;

//define number of time steps:
size_t T = measurement_pack_list.size();

//cycle:
for (size_t t = 0; t < T; ++t){

//Call 1d_bayesian filter:
localization_1d_bayesian.ProcessMeasurement(measurement_pack_list[t],
map_1d,
helper);
}

```

## Assumptions

This code implements 1D Markov localization and assumes that 

- A landmarks based 1D map `m` is given 
- The sensor measures the distances to nearest `k` landmarks on the road, in the driving direction. 
- The sensor has `standard deviation` of `1m`.

## Learn the Math Behind Markov Localization (Bayesian Filter)

I did take [notes](https://drive.google.com/open?id=0Bxv9kPZMr-zbWFBXUXp4UHRyNzA) when I was learning which (although not very neat) may be helpful. Other than that, there are plenty of resources on the web to learn from.


