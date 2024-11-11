n=int(input())

l=list(map(int,input().split()))
k=[n]
i=n-2
temp=0
while(temp!=1):
    k.append(l[i])
    i=l[i]-2
    temp=l[i]
print(*sorted([1]+k))
