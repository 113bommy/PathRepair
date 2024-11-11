v=['a', 'e', 'i', 'o', 'u', 'y']
n=int(input())
l=list(map(int,input().split()))
f=0
for u in range(n):
    s=input()
    c=0
    for i in s:
        if(i in v):
            c+=1
    if(c<l[u]):
        f=1
if(f==1):
    print("NO")
else:
    print("YES")
