n = input()
d = [0 for _ in range(9)]
seq = [int(x) for x in input().split()]
for val in seq:
    val = min(val, 3300)
    d[(val // 400)] += 1
a = sum(1 for val in d[:-1] if val > 0)
print(max(1,a), min(8,a + d[-1]))