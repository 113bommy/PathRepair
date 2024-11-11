n=int(input())
l=[int(input()) for i in range(n)]
l.sort()
s=sum(l)
for i in range(n):
    if s%10!=0:
        print(s)
        break
    else:
        if l[i]%10!=0:
            s-=l[i]
else:
    print(0)