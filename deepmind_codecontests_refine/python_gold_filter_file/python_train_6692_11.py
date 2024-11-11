t=int(input())
for i in range(t):
    x=input()
    cur1=int(x[0])
    cur2=len(x)
    if cur2==3:
        cur2=6    
    if cur2==2:
        cur2=3
    if cur2==4:
        cur2=10
    print((cur1-1)*10+cur2)