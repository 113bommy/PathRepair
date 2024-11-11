n=input().split(' ')
n1=int(n[0])
n2=int(n[1])
a=input().split(' ')
d2=0
d=0
lol=0
for i in range(len(a)):
    a[i]=int(a[i])
a.sort()
for i in range(len(a)):
    for h in range(len(a)):
        if a[h]-a[i] <= n2 and h-i > lol:
            lol=h-i            
print(n1-lol-1)
