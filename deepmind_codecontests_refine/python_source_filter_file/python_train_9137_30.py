n, p = map(int,input().split())
D = input()
out = 0


if 10 % p == 0:
    for i in range(n):
        if int(D[i]) % p == 0:
            out += i + 1
else:
    mod = 0
    count = [0] * p
    ten = 1
    count[mod] += 1
    for i in range(n):
        mod = (mod + int(D[n-i-1]) * ten) % p
        ten = ten * 10
        count[mod] += 1
    for c in count:
        out += (c * (c - 1)) // 2
print(out)