n=int(input())
for i in range(4):
    a,b,c,d = map(int,input().split())
    e = min(a,b)
    f = min(c,d)
    if((e+f)<=n):
        print(i+1,e,n-e)
        exit()
print(-1)