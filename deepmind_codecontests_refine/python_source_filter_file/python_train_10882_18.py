n, m = map(int, input().split())
A, T = set(map(int, input().split())), set()

for i in range(1, 100000):
    if i > m:
        break
    if i not in A:
        m -= i
        T.add(i)

print(len(T))
print(*T)