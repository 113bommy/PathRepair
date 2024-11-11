import math

from random  import randint
#t = int(input())
t=1
while t>0:
    t-=1; places = []
    n = int(input())
    for _ in range(3):
        places.append(int(input()))
    smallest = min(places)
    n-=1; dist =0
    if places.index(smallest)==2 and n>0:
        dist += min(places[:2])
    n-=1
    #print(dist, places)
    if n>0:
        dist += n*smallest
    print(dist)