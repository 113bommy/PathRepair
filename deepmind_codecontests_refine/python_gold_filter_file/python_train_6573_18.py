n,k=map(int,input().split())
arr=[int(x) for x in input().split()]
l=[]
for i in range(k):
    l.append(0)
for i in range(n):
    l[arr[i]-k*(arr[i]//k)]+=1
sum=2*(l[0]//2)
for i in range(1,k//2+1):
    if i==k-i:
        sum+=2*(min(l[i],l[k-i])//2)
    else:
        sum+=2*min(l[i],l[k-i])
#print(l)
print(sum)