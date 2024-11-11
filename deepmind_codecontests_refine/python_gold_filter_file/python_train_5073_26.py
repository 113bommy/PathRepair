n,b=map(int,input().split())
lst=list(map(int,input().split()))
c=[]
t=0
for i in range(len(lst)-1):
    if lst[i]%2==0:
        t+=1
    else:
        t-=1
    if t==0:
        c.append(abs(lst[i+1]-lst[i]))
c.sort()
j=0
while j<len(c) and b>=0:
    b-=c[j]
    if b>=0:
        j+=1
print(j)
        