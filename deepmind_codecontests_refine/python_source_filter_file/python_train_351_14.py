import math
n=int(input())
l=list(map(int ,input().split()))
a=sum(l)
print(max(max(l),math.ceil(a/n-1)))