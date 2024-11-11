from sys import stdin
from math import gcd
inp = stdin.readline

n, k = [int(x) for x in inp().strip().split()]

array = [int(x) for x in inp().strip().split()]

typeOfBoxes = 1
numberOfBoxes = n//array[0]
for i in range(1,k):
    if n%array[i] < n%array[typeOfBoxes]:
        typeOfBoxes = i + 1
        numberOfBoxes = n//array[i]
    
print(typeOfBoxes, numberOfBoxes)