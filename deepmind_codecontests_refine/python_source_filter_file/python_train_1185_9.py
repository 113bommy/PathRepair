##### import math
#n=int(input())
a,b,c,d = map(int, input().strip().split(' '))
#lst = list(map(int, input().strip().split(' ')))
a1=a/b
r=(a/b)*(1-c/d)
print(a1/(1-r))