n,b = [int(x) for x in input().strip().split(' ')]
a=[int(x) for x in input().strip().split(' ')]
odd=0
eve=0
c=[]
for i in range(n):
    if a[i]&1:
        odd+=1
    else:
        eve+=1
    if i<(n-1) and odd==eve:
        c.append(abs(a[i+1]-a[i]))
c.sort()
l = len(c)
j=0
ans=0
while j<l:
    b-=c[j]
    if b>=0:
        ans+=1
    else:
        break
    j+=1
print(ans)