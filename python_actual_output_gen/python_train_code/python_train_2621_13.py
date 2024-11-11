n = int(input())
l = []
for _ in range(n):
    l.append(int(input()))
time = len(l)
if len(l) == 1:
    print(time + l[0])
else:
    for i in range(len(l) - 1):
        if i == 0:
            time += l[i]
        if l[i + 1] < l[i]:
            time += l[i] - l[i + 1]
            time += 1
        elif l[i] == l[i + 1]:
            time += 1
        elif l[i] < l[i + 1]:
            time += 1
            time += l[i + 1] - l[i]
        print(time)
