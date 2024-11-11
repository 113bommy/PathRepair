n = int(input())

s = set()
for _ in range(n):
    s ^= {input()}

print(len(s))
