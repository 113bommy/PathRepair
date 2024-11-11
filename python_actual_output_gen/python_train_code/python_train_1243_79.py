n,x=map(int,input().split())
nope=0
for loop in range(n):
    signe,d=input().split()
    d=int(d)
    
    if signe=="+":
        x+=d
    else:
        if x-d>=0:
            x-=d
        else:
            nope+=1
print(n,nope)