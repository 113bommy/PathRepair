N = int(input())

a = list(map(int,input().split()))
b = list(map(int,input().split()))

total1 = 0
total2 = 0

for i in range(N):
    if a[i]>b[i]:
        total1 += a[i]-b[i]
    else:
        total2 += b[i]-a[i]

if total1 <=total2/2:
    print('Yes')
else:
    print('No')