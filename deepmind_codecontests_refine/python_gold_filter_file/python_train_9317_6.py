n=int(input())
for x in range(n,0,-1):
    if n%x==0:
        print(x,end=' ')
        n=x