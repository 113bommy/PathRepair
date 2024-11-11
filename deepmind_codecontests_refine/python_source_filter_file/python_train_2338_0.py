n=int(input())
a=list(map(int,input().split()))
h=0
sums=0
fzeropoint=0
minus=0
result=0
j=0
l=n-1
i=0
for y in range(n):
    h=h+a[y]
if h%3!=0:
    print(0)
else:
    for k in range(n):
        sums=sums+a[k]
        if sums==h//3:
            fzeropoint=fzeropoint+1
            break
    sums=0
    while l>k:
        sums=sums+a[l]
        if sums==h//3:
            break
        l=l-1
    sums=0
    i=k+1
    j=l-1
    while i<l-1:
        sums=sums+a[i]
        if sums==0:
            fzeropoint=fzeropoint+1
        i=i+1
        minus=sums
    if l!=k:
        result=fzeropoint+result
    sums=0
    while j>k+1:
        if minus==0:
            fzeropoint=fzeropoint-1
        minus=minus-a[j-1]
        sums=sums+a[j]
        if sums==0:
            result=result+fzeropoint
        j=j-1
    print(result)
