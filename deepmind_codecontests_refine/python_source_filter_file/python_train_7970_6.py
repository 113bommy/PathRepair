n,k = list(map(int,input().split()))
tl = 240-k
if 5*(n*(n+1)/2) < tl:
    print(n)

for item in range(1,n+1):
    if 5*(item*(item+1)/2) == tl:
        print(item)
    elif 5*(n*(n+1)/2) > tl and 5*(item*(item+1)/2) < tl and 5*(item+1)*(item + 2)//2 > tl:
        print(item)
