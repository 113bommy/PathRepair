n = int(input())
days = list(map(int, input().split()))
for i in range(1, n):
    days[i] += days[i-1]
for i in range(n):
    if days[i]*2 > days[n-1]:
        print(i+1)
        break
