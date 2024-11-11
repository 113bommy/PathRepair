from sys import stdin
n=int(stdin.readline().strip())
l=list(map(int,stdin.readline().split()))
co=0
ce=0
a=[]
b=[]
for i in range(n):
    if l[i]%2==0:
        co+=1
        a.append(l[i])
    else:
        ce+=1
        b.append(l[i])
if co==ce or co-ce==1 or ce-co==1:
    print(0)
else:
    k=min(co,ce)
    a.sort(reverse=True)
    b.sort(reverse=True)
    if k!=0:
        for i in range(k):
            a.pop()
            b.pop()
    if len(a)>len(b):
        a.pop()
    else:
        b.pop()
    print(sum(a)+sum(b))