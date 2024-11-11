m = []
for i in range(0, 10):
    m.append(int(input()))
m.sort(reverse=True)
for i in range(0, 3):
    print(m[i])