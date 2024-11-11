from statistics import median as m
n=int(input())
A=list(map(int,input().split()))
B=sorted([A[i]-i-1 for i in range(n)])
m(B)=mb
print(int(sum([abs(b-mb) for b in B])))