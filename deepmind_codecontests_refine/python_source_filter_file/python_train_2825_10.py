n=int(input())
yep=False
for i in range(n+1):
    if (n-4*i)%7==0 and (n-4*i)>0:
        print("4"*i+((n-4*i)//7)*"7")
        yep=True
        break
if not yep:
    print(-1)
