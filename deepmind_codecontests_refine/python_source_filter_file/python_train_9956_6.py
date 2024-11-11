a,b,c=map(int,input().split())
for i in range(200000):
    if a>b:
        x=a//b
        a=a%b
        a*=10
    else:
        x=0
        a*=10#0.4117647058823529
    if x==c and i>0:
        print(i)
        break
else:
    print(-1)