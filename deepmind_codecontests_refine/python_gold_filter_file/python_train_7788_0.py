import collections

n = int(input())
a = list(map(int,input().split()))
a1 = collections.Counter(a[0::2]).most_common()
a2 = collections.Counter(a[1::2]).most_common()
a1.append((0,0))
a2.append((0,0))
#print(a1)
#print(a2)

if a1[0] != a2[0]:
    print(n-a1[0][1]-a2[0][1])
else:
    print(min(n-a1[0][1]-a2[1][1],n-a1[1][1]-a2[0][1]))

