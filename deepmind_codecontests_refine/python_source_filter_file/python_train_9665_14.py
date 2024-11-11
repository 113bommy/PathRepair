n = int(input())
a = set()
for _ in range(n):
    a ^= set(input())
print(len(a))