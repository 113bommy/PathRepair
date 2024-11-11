line = list(map(int, input().split()))
line.sort()
for i in line:
    if i % line[0] != 0:
        print(-1)
        break
else:
    print(line[0])
