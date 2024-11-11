import functools, operator, sys
n = int(input())
A = list(map(int, input().split()))
if not n & 1:
    if functools.reduce(operator.xor, A):
        print("NO")
        sys.exit()
    n -= 1
print("YES")
print(n - 1)
for i in range((n - 1) // 2):
    tmp = [1, i * 2 + 2, i * 2 + 3]
    print(*tmp)
for i in range((n - 1) // 2):
    tmp = [1, i * 2 + 2, i * 2 + 3]
    print(*tmp)