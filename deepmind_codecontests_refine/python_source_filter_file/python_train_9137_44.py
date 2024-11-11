from collections import Counter
n,p=map(int,input().split())
s=input()

ans=0
if p==2 or p==5:
    for i,j in enumerate(s):
        if int(j)%p==0:
            ans +=i+1
else:
    num,point=0,1
    A=[0]
    for i in s[::-1]:
        num +=int(i)*point
        num %=p
        A.append(num)
        point *=10
        point %=p

    A=Counter(A)
    for i,j in A.items():
        if j>=2:ans +=i*(i-1)//2
print(ans)