i,j=map(int,input().split())
a=[4,7]
l=0
m=-1
k=list(str(j))
k=len(k)

while l<k:
    for m in range(m+1,len(a)):
        a.append(str(a[m])+"4")
        a.append(str(a[m])+"7")
    l+=1
sum=0

print(a)
for m in range(len(a)):
    if i<=int(a[m]) and j>int(a[m]):
        sum+=int(a[m])*(int(a[m])-i+1)
        i=int(a[m])+1
    elif i<=int(a[m]) and j<=int(a[m]) and i<=j:
        sum+=int(a[m])*(j-i+1)
        break
    #print(i,j)
print(sum)
