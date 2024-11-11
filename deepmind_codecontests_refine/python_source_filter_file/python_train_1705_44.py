n,m=map(int,input().split())
minn=min(n,m)
print(minn+1)
for i in range(minn):
    print(i,minn-i)