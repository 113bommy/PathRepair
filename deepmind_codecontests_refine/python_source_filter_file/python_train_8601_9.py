i = 1
v = []
while i < 1e5:
    v.append(int(str(i) + str(i)[::-1]))
    i += 1

k, p = map(int, input().split())
print(sum(v[:k]) % p)
