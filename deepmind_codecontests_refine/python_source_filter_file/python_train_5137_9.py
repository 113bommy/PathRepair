from sys import stdin, stdout


def gethash(l, r, label):
    if not label:
        return (hsh1[r] - hsh1[l - 1] * power[r - l + 1]) % MOD
    else:
        return (hsh2[r] - hsh2[l - 1] * power[r - l + 1]) % MOD


def equalsubstr1(l1, r1, l2, r2):
    return gethash(l1, r1, 0) == gethash(l2, r2, 0)


def equalsubstr2(l1, r1, l2, r2):
    return gethash(l1, r1, 1) == gethash(l2, r2, 1)



first = stdin.readline().strip()
second = stdin.readline().strip()

if len(first) != len(second):
    first, second = min(first, second, key = lambda x: len(x)), max(first, second, key = lambda x: len(x))
    
n, k = len(first), len(second)
dividers = []


x = 137
MOD = 10 ** 9 + 7
power = [1]

for i in range(k + 1):
    power.append((power[-1] * x) % MOD)
    
hsh1 = [ord(first[0])]
for i in range(1, n):
    hsh1.append((hsh1[-1] * x + ord(first[i])) % MOD)
hsh1.append(0)

hsh2 = [ord(second[0])]
for i in range(1, k):
    hsh2.append((hsh2[-1] * x + ord(second[i])) % MOD)
hsh2.append(0)

for i in range(1, int(n ** 0.5) + 1):
    if not n % i:
        dividers.append(i)
        if (n // i != i):
            dividers.append(n // i)

dividers.sort()
challengers = []

for v in dividers:
    for i in range(0, n - v + 1, v):
        
        if not equalsubstr1(i, i + v - 1, 0, v - 1):
            break
        
    else:
        if not k % v:
            challengers.append(v)


ans = []
for v in challengers:
    for i in range(0, k - v + 1, v):
        
        if not equalsubstr2(i, i + v - 1, 0, v - 1):
            break
        
    else:
        ans.append(v)


stdout.write(str(len(ans))) 