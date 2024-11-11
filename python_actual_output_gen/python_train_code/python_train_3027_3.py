n=int(input())
l=list(map(int,input().split()))
x,y=map(int,input().split())
for i in range(1,n-1):
    if x<=sum(l[:i])<=y and x<=sum(l[i:])<=y: print(i+1); break
else: print(0)