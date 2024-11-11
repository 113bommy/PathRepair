k,t=map(int,input().split())
a=list(map(int,input().split()))
A=max(a)
print(max(A-1-(k-A),0))

