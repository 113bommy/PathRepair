n,b=map(int,input().split())
a=list(map(int,input().split()))
l=[]
c=0
e=0
o=0
for i in range(len(a)):
    c+=1
    if a[i]%2==0:
        e+=1
    else:
        o+=1
    if e==o and c<len(a):
        if a[i+1]-a[i]<=b:
            e=0
            o=0
            l.append(abs(a[i+1]-a[i]))
l.sort()
c=0
for i in l:
    b-=i
    if b<0:
        break
    else:
        c+=1
print(c)