l, r = map(int, input().split())
two = []
three = []
for i in range(30):
    two.append(2 ** i)
for i in range(19):
    three.append(3 ** i)
s = set()
for i in range(30):
    for j in range(19):
        s.add(two[i] * three[j])
k = 0
for i in s:
    if l <= i <= r:
        k += 1
print(k)
