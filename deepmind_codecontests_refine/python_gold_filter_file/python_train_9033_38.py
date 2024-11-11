n,k=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=True)[k:]
print(sum(a))