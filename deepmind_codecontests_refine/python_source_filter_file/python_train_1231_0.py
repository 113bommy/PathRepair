n,h=map(int,input().split())
a,b=[],[]
for _ in range(n):
    A,B=map(int,input().split())
    a+=[A]
    b+=[B]
c=max(a)
b.sort()
ans=0
for i in b[::-1]:
    if i>c:
        h-=i
        ans+=1
    else:
        break
print(ans-(-h//c)*(h>0))