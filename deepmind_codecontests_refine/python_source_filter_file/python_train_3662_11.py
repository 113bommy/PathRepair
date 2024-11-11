import math

# print(math.floor(2**(8/6)))
n, k = map(int, input().split())
if k>=100000:
    print("0")
    exit()
disti = math.floor(2 ** math.floor(8 * k / n))
# while math.ceil(math.log(disti,2))*n/8>k:
#     disti-=1
# print(disti)
a = list(map(int, input().split()))

# print(disti)
if len(set(a)) <= disti:
    print("0")
    exit()
# print(disti)
a = sorted(a)
d = dict()
for i in range(len(a)):
    d[a[i]] = d.get(a[i], 0)
    d[a[i]] += 1
p = []
for i in sorted(d.keys()):
    p.append(d[i])
ans = 0
# remove=len(set(a))-disti
# print(p)
# print("REMONE",remove)
for i in range(disti):
    ans += p[i]
window = ans
for i in range(disti, len(p)):
    window -= p[i - disti]
    window += p[i]
    if window > ans:
        ans = window

print(sum(p) - ans)