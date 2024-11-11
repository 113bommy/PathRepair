n = int(input())
l = [*map(int, input().split())]
print(n + 1)
curr = 0
for i in range(n - 1, -1, -1):
    print(f'1 {i + 1} {i + (-(curr + l[i]) % n)}')
    curr += i + (-(curr + l[i]) % n)
print(f'2 {n} 1')