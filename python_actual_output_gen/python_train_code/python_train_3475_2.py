s = input()
K = int(input())

l = {s}
for n in range(1, K):
    for i in range(0, len(s)-n+1):
        l.add(s[i:i+n])

l = list(l)

l.sort()

print(l[K-1])