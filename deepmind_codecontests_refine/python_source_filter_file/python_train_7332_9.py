#Megacity
import math
n, s = map(int, input().split())

class Boundary:
    def __init__(self,x,y,population):
        self.radius = round(math.sqrt(x*x + y*y),7)
        self.population = population
    def __lt__(self, other):
        return self.radius > other.radius

arr = []
for i in range(n):
    x, y, population = map(int,input().split())
    arr.append(Boundary(float(x), float(y),population))
populationNeed = 1000000 - s
sum = 0
resultRadius = 0.0000000
arr.sort()
for i in range(len(arr)):
    sum += arr[i].population
    if sum >= populationNeed:
        resultRadius = arr[i].radius
        break
if sum >= populationNeed:
    print(resultRadius)
else:
    print(-1)