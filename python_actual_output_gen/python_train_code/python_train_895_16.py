from collections import Counter
n = int(input())
soma = 0
cont = 0
c = list(map(int, input().split()))
counter = Counter(c)
while len(set(c)) != len(c):
    for i in range(len(c)):
        if i >= len(c):
            break
        counter[c[i]] -= 1
        cont = counter[c[i]]
        if c[i] - cont > 0:
            counter[c[i] - cont] += 1
        c[i] -= cont
        if c[i] <= 0:
            c.remove(c[i])
            i -= 1
for x in c:
    soma += x
print(c)
print(soma)
