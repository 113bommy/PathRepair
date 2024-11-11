a,b=map(int,input().split())
c=list(map(int,input().split()))
x=0
for i in range(1,a):
    if (c[i]-c[i-1])<=b:
        x+=1
    else:
        x=1
print(x)
    
