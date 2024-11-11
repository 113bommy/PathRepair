import string

s=input()
k=int(input())
total=0
l=list(map(int,input().split()))
c=max(l)
z=len(s)
ls=string.ascii_lowercase
for x in range(z):
    if s[x] in ls:
        total+=l[ls.find(s[x])]+x+1
for i in range(1,k+1):
    total+=c*(z+i)
print(total)