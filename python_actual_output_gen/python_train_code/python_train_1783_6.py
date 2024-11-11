a,b=map(int,input().split())
n=[int(i) for i in input().split()]
s=0
n.sort()
c=0
for i in range(a):
    if(n[i]<=0 and c<=b):
        s+=n[i]
        c+=1
s=abs(s)
print(s)