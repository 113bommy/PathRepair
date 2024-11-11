n = int(input())
a = [int(i) for i in input().split()]
maxa = max(a)
cnt = a.count(maxa)
if n == cnt:
    if cnt % 2:
        print("Conan")
    else:
        print("Agasa")
    exit(0)
p = [0] * (10**5 + 1)
for i in a:
    p[i] += 1
for i in range(10**5, 0, -1):
    if p[i] % 2:
        print("Conan")
        break
else:
    print("Agasa")
