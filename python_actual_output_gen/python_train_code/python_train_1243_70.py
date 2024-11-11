n,c=map(int,input().split())
d=0
for i in range(n):
    s,t=map(str,input().split())
    x=int(t)
    if s=="+":
        c+=x
    elif s=="-":
        if (c-x)>0:
            c-=x
        else:
            d+=1
print(c,d)        