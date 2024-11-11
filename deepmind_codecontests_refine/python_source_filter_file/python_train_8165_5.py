input()
p = [0] * 100001
s = input().split()
for k in s:
    p[int(k)] += 1
for i in range(1, 100001):
    p[i] = max(p[i-1], p[i-2] + i*p[i])
print(p[-1])


