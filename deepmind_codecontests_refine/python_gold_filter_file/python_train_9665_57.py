n = int(input())
a = set()
for _ in range(n):
    a ^= {input()}
print(len(a))