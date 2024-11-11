n=int(input())
l=[int(x) for x in input().split()]
a=l.count(5)
b=0
c=0
for i in range(n):
    if(l[i]==0):
        b=1
        c=l.count(0)
        break
if(b==0):
    print(-1)
else:
    if(a//9>=1):
        print("5"*9*(a//9)+"0"*c)
    else:
        print(0)