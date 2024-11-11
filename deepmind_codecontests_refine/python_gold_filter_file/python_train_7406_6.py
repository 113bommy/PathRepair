n=int(input())
a=list(map(int, input().split()))
maxi=0
x=0
mini=10000000000
maxii=-1
for i in range(n):
    if a[i]==1:
        x+=1
        if x>maxi:
            maxi=x
    else:
        if i>maxii:
            maxii=i
        if i<mini:
            mini=i
        x=0
print(max(maxi, sum(a[0:mini])+sum(a[maxii:n])))