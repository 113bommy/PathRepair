from sys import stdin
import sys
import math
class PriorityQueueBase:
    class _Item:
        __slots__ = '_key','_value'

        def __init__(self,k,v):
            self._key = k
            self._value = v

        def __lt__(self,other):
            return self._key < other._key

    def is_empty(self):
        return len(self) == 0

def queue_time(customers,n):
    for i in range(1,len(customers)):
        i = i%n
        while i%n<n and customers[i%n]>customers[(i+1)%n]:
            i+=1
            customers[i%n] =customers[i%n] + customers[i]
            customers[i] = 0
    return customers

def phi(n):
    result = n
    for i in range(2,int(pow(n,0.5))+1):
        while n%i == 0:
            n/=i
            result-=result/i
    if n>1:
        result -= result/n
    return result

input = stdin.buffer.readline
n = int(input())
a = list(map(int,input().split()))
one = a.count(1)-1
two = a.count(2)-1
if one>=1 and two>=1:
    c = [2,1]
else:
    print(*a)
    sys.exit()
for i in range(two):
    c.append(2)
for i in range(one):
    c.append(1)
print(*c)





