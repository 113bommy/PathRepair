I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
n=I()
a=LI()
b=1;ans=0
for i in range(n):
    if a[i]>=b:
        ans+=1
        b+=1
print(ans)