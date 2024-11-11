n,k=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=True)[k-1:]
print(sum(a))