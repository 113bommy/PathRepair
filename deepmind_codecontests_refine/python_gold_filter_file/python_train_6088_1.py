d = {'polycarp': 1}
for i in range(int(input())):
    a, b, c = input().lower().split()
    d[a] = d[c] + 1
print(max(d.values()))
