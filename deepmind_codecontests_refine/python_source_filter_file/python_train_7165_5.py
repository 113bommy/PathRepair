N = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

sum1 = 0
sum2 = 0
for i in range(N):
    if a[i] > b[i]:
        sum1 += a[i] - b[i]
    else:
        sum2 += b[i] - a[i]
if 2*sum1 <= sum2:
    print('Yes')
else:
    print('No')