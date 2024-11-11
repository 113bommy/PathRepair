n,x,y=map(int,input().split())
a=list(map(int,input().split()))

if x>y:
    print(n)
elif x==y:
    b=[]
    for z in a:
        if z<=x: b.append(z)
    print((len(b)+1)//2)
