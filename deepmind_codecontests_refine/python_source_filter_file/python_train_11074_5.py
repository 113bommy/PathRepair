def to_prime(n):
    step = 0
    i = n
    while not is_prime[i]:
        step += 1
        i += 1
    return step
R = 10 ** 5 + 1   
is_prime = [0] * (R + 1)
is_prime[1] = 1
d = 2
while d * d <= R:
    if not is_prime[d]:
        for i in range(d ** 2, R + 1, d):
            is_prime[i] = 1
    d += 1
for i in range(R + 1):
    if is_prime[i]:
        k = i
        step = 0
        while k <= R and is_prime[k]:
            k += 1
            step += 1
        is_prime[i] = step
n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int,input().split())))
min_step = 10**5
for j in range(n):
    step = 0
    i = 0
    while i < m:
        if is_prime[a[j][i]] > 0:
            step += is_prime[a[j][i]]
        i += 1    
    if step < min_step:
        min_step = step
for j in range(m):
    step = 0
    i = 0
    while i < n:
        if is_prime[a[i][j]] > 0:
            step += is_prime[a[i][j]]
        i += 1
    if step < min_step:
        min_step = step
print(min_step)