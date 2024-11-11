from collections import Counter

n = int(input())
v = list(map(int, input().split()))

odd = v[::2]
even = v[1::2]

ac = Counter(odd).most_common(2)
bc = Counter(even).most_common(2)

if ac[0][0] != bc[0][0]:
    print(n-ac[0][1]-bc[0][1])
else:
    if len(ac) == 1 or len(bc) == 1:
        print(n//2)
    else:
        print(n-max(ac[0][1]+bc[1][1], ac[1][1]+bc[0][1]))