s, p, k = {}, '', 0
for q in input().split():
    s[q] = s.get(q, 0) + 1
    if s[q] > k: p, k = q, k + 1
print(p)