a,b=list(map(int,input().split()))
t=0
for k in range(1,100000):
    for j in range(1,a+1):
        if j<=b:
            b-=j
        else:
            print(b)
            t=1
            break
    if t==1:
        break
if t==0:
    print(b)
        
