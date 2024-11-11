from math import ceil
a=list(map(int,input().split()))
b=list(map(int,input().split()))
n=int(input())
print("YES") if n-ceil(sum(a)/5)-ceil(ceil(sum(a)/5))>=0 else print("NO")
