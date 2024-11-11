import sys
a,b,c=map(int,input().split())
i=1
while i<1000:
    a*=10
    cur=a//b
    if cur==c:
        print(i)
        sys.exit()
    a%=b
    i+=1
print(-1)
