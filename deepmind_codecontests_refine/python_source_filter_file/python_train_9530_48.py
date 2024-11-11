n=int(input())
flag=0
for i in range(n):
    a,b,c=input().split()
    b=int(b)
    c=int(c)
    if(b>=2400 and b>c):
        flag=1

if(flag):
    print("YES")
else:
    print("NO")