#constructive algorithm, graph
#Self-loop is not a cycle :xD
from math import sqrt,ceil
n,m = map(int, input().split())
Min = n - 2*m
Min  = max(0,Min)
Max = int(n - ceil((1 + sqrt(1+8*m))/ 2))
Max = max(0,Max)
if(m==0):
    Min = Max = 0
print(Min, Max)