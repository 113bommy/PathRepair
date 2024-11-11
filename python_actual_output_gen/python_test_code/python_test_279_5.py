n= int(input())

a = list(map(int, input().split()))

if n == 0 and a[0]==1:
    print(1)
    exit(0)


if a[0] != 0:
    print(-1)
    exit(0)


b=1
count=1
asum =sum(a)
alim = asum

for i in range(n-1):
    if a[i+1] > 2*b:
        print(-1)
        exit(0)
    else:
        alim = alim - a[i+1]
        b= min(2*b-a[i+1], alim)

        count += b



print(count+ asum)