N = int(input())
a = list(map(int, input().split()))

sum = 0
for i in range(N):
    sum ^= a[i]

    print('Yes' if sum == 0 else 'No')
