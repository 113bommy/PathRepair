a = []
for _ in range(6):a.append(sorted(list(map(int, input().split()))))
a.sort(key = lambda x:x[1])
a.sort(key = lambda x:x[0])
print("yes" if a[0] == a[1] and a[2] == a[3] and a[4] == a[5] and a[0][0] == a[2][0] and a[0][1] == a[3][0] and a[2][1] == a[3][1] else "no")
