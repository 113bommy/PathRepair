import sys
n,k=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
s=sum(a)
if s%k!=0:
    print("NO")
    sys.exit(0)
tot=s//k
ans=[]
cur=0
cursum=0
for i in a:
    cursum+=i
    cur+=1
    if cursum>tot:
        print("NO")
        sys.exit(0)        
    elif cursum==tot:
        ans.append(cur)
        cur=0;cursum=0
if cur!=0:
    print("NO")
    sys.exit(0)
print("YES")
for i in ans:
    print(i,end=' ')