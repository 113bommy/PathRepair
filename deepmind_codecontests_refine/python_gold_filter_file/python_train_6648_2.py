import collections 
n,k=map(int,input().split())
p=[str(input()) for _ in range(n)]
for i in range(n):
    p[i]=p[i][0:1]
#print(p)
c=collections.Counter(p)
#print(c)
a=[]
for v in c.values():
    a.append(v)
#print(a)
a.sort(reverse=True)
ans=0


#print(a)
while True:
    a.sort(reverse=True)
    if k<=len(a):
        ans+=1
        for i in range(k):
            a[i]-=1
        for i in range(k-1,-1,-1):
            #print(a[i])
            if a[i]==0:
                a.pop(i)
        #print(a)
    else:
        break

print(ans)
