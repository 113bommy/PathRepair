from math import ceil
n,m=map(int,input().split())
d=ceil(n*m//(m-1))-1
print(d)