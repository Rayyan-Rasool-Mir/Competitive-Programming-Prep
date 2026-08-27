/*Earning A Profit
There are \(N\) planets numbered \(1\) to \(N\). 
You are a space merchant who earns by selling goods on these planets. 
Traveling to each planet requires you to pay for the fuel. 
The difficulty of traveling to \(i\)-th planet is \(D_{i}\). 
You need to plan your trip by choosing a consecutive sub segment of planets.
Your earning of the trip is calculated as follows -You earn \(A\) coins for every planet you visit.
For each planet \(i\) you visit, you have to pay \(C_{i}\) coins for the fuel.
If you visit every planet with indices \(L\) to \(R\), 
you also have to pay \(gap(L, R)\) coins where \(gap(L, R) = max[(D_r - D_l)^2]\) 
for \(L <= l <= r <= R\)Calculate the maximum profit you can earn by traveling to a consecutive segment of planets. 
Note that if you travel to no planet at all, your net profit will be zero.*/