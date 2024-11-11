n,k=map(int,input().split())
l=sorted(map(int,input().split()))[::-1]
print(sum(l[:k+1]))