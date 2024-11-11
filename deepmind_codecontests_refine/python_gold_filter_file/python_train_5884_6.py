def dec_to_bin(n):
    ans = ''
    while n > 0:
        ans += str(n % 2)
        n //= 2
    return ans[::-1]


a, b = map(int, input().split())
binaries = [10]
for i in range(2, 61):
    s = i * '1'
    for k in range(1, i + 1):
        s = s[:k] + '0' + s[k:]
        binaries.append(s)
        s = s[:k] + s[k + 1:]
abin = int(dec_to_bin(a))
bbin = int(dec_to_bin(b))
binaries = sorted(list(map(int, set(binaries))))
ans = 0
for j in range(len(binaries)):
    if bbin >= binaries[j] >= abin:
        ans += 1
print(ans)
