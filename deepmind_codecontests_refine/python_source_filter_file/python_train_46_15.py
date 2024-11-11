from collections import Counter

input()
s = Counter(int(x) for x in input().split())
xs = Counter(int(x) for x in input().split())
ys = Counter(int(x) for x in input().split())
 
d = s - xs
a = d.most_common(1)[0]

x = s - ys
x[a] -= 1
b = x.most_common(1)[0]
print(a)
print(b)