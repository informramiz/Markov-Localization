# Markov-Localization (Bayesian Filter)

Localize a vehicle in a given map and sensors data, using Markov Localization. This code follows a very simple form of 1D Markov Localization.

## Assumptions

This code implements 1D Markov localization and assumes that 

- A landmarks based 1D map `m` is given 
- The sensor measures the distances to nearest `k` landmarks on the road, in the driving direction. 
- The sensor has `standard deviation` of `1m`.

## Learn the Math Behind Markov Localization (Bayesian Filter)

I did take [notes](https://drive.google.com/open?id=0Bxv9kPZMr-zbWFBXUXp4UHRyNzA) when I was learning which (although not very neat) may be helpful. Other than that, there are plenty of resources on the web to learn from.


