from math import ceil
n,w,perc=list(map(int,input().split()))
print(ceil(n*(perc/100))-w)