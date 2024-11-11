from itertools import accumulate

n = int(input())

mas = list(map(lambda x: 0, range(101)))

x0, y0 = map(int, input().split())

for i in range(n - 1):
    x, y = map(int, input().split())
    
    mas[x] += 1
    mas[y] -= 1

ans = list(accumulate(mas[x0:y0])).count(0)

print(ans)
