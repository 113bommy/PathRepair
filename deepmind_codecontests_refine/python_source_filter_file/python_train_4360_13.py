def mark(s, x):
    for i in range(x + x, len(s), x):
        s[i] = False

def sieve(n):
    s = [True] * n
    for x in range(2, int(n**0.5) + 1):
        if s[x]: mark(s, x)
    return [i for i in range(0,n) if s[i] and i > 1]

n = []
while True:
    tmp = int(input())
    if tmp == 0:
        break
    n.append(tmp)
m = max(n)
p = sieve(10000)

for i in range(len(n)):
    sum = 0
    if n[i] == 1:
        print(2)
    else:
        for j in range(n[i]):
            sum += p[j]
        print(sum)