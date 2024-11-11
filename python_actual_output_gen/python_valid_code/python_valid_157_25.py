n,k=map(int,input().split())
l=list(map(int,inout().split()))
print(sum(sorted(l)[:k][::-1]))