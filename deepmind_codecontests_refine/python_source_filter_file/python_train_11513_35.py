n, k = map(int, input().split())
if k == 26:
    unique = [int(i) for i in range(1, 26)]
else:
    import random
    unique = random.sample(range(1, 26), k)
result = []
for i in range(n):
    result.append(chr(97 + unique[i % len(unique)]))
print("".join(result))