n = int(input())
a = set()
for _ in range(n):
    a ^= {int(input())}
print(len(a))