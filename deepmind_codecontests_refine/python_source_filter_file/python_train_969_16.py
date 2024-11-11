n = int(input())
asdf = input().split()
a = []
for bs in asdf:
    a.append(int(bs))
s = 0
for i in range(1, n):
    if a[i] > max(a[:i]) or a[i] < max(a[:i]):
        s += 1
print (s)