import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().rstrip().split())
inl = lambda: list(map(int, input().split()))
out = lambda x: print('\n'.join(map(str, x)))

n = ini()
a = inl()
count = [0] * 200001
for i in a:
    count[i] += 1
if max(count) > 2:
    print("NO")
else:
    inc = []
    incc = 0
    dec = []
    decc = 0
    for i in range(200000):
        if count[i] == 1:
            inc.append(i)
            incc += 1
        elif count[i] == 2:
            inc.append(i)
            dec.insert(0, i)
            incc += 1
            decc += 1
    print("YES")
    print(incc)
    print(*inc)
    print(decc)
    print(*dec)