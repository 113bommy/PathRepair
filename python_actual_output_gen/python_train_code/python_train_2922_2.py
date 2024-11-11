n=int(input())
z=0
for i in range(n):
    s,d=map(int,input().split())
    if z <= s:
        z=s
    else:
        x=s%d
        y=z%d
        if x>=y:
            f=(x-y)%d
            z+=f
        else:
            f=(x-y)%d
            z+=f
    #print(z,s)
print(z)
    
