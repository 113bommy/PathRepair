n,m=map(int,input().split())
g=m//2
k=m-g
for i in range(m):
    if i%2==1:
        a=n-g-((i+1)//2)+1
        b=a+i+1
        print(a,b)
    else:
        a=k-(i//2)
        b=a+i+2
        print(a,b)
