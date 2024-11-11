l = int(input())
a = list(map(int, input().split()))
d = []
for i in range(1, l):
    if (a[i] == max(a[:i+1]) or a[i] == min(a[:i+1])) and (a[i] not in d) and (a[i] != a[0]):
        d.append(a[i])
print(len(d))