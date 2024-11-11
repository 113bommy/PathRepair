n = int(input())
ans = 0
ansl = []
while bin(n)[2:].find('0') != -1:
    a = bin(n)
    ansl.append((len(a) - 2) - a[2:].find('0'))
    n = n ^ (2 ** ((len(a) - 2) - a[2:].find('0')) - 1)
    ans += 1
    if bin(n)[2:].find('0') != -1:
        n = n ^ 1
        ans += 1
print(ans)
print(' '.join(list(map(str, ansl))))