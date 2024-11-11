n=int(input())
f=[0 for i in range(n+1)]
for i in range(n-1):
    x,y=map(int,input().split())
    f[x]+=1
    f[y]+=1
print(max(f))
