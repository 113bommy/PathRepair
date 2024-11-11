f = lambda: map(int,input().split())
n,k=f()
a=sorted(list(f()))[::-1]
for x in a:
    if k%x==0:
        print(k//x)
        break
