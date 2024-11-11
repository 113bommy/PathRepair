x=list(map(int,input().split()))
k=int(input())
print(max(x)*k+sum(x)-max(x))