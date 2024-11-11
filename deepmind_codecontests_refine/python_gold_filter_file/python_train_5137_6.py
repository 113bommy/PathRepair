from sys import stdin, stdout


def equalsubstr1(l1, r1, l2, r2):
    return first[l1: r1 + 1] == first[l2: r2 + 1]


def equalsubstr2(l1, r1, l2, r2):
    return second[l1: r1 + 1] == first[l2: r2 + 1]


first = stdin.readline().strip()
second = stdin.readline().strip()

if len(first) != len(second):
    first, second = min(first, second, key = lambda x: len(x)), max(first, second, key = lambda x: len(x))

n, k = len(first), len(second)
dividers = []

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