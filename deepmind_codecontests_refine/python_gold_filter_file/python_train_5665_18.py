n=int(input())
a,b,c=[0]*3
for i in range(n):
    x,y=[int(v) for v in input().split()]
    if x%2==0:
        if y%2==1:
            b=1-b
            c=1
    else:
        a=1-a
        if y%2==0:
            c=1
        else:
            b=1-b
            
if a==0 and b==0:
    print(0)
elif a==1 and b==1 and c==1:
    print(1)
else:
    print(-1)
        