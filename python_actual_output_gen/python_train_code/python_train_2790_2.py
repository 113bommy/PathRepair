f=lambda:map(int,input().split())
n,k=f()
l=sorted(list(set(f())))
print(l[0])
k-=1
i=0
while k!=0 and i<len(l):
    if l[i]-l[i-1]!=0:
        print(l[i]-l[i-1])
    i+=1
    k-=1
for i in range(k,0,-1):
    print(0)
