

n = int(input())
l = input().split()
l.insert(0, 0)
l.append(90)
rs = 90
for i in range(1, n + 1):
    if int(l[i]) - int(l[i-1]) > 15:
        rs = int(l[i-1]) + 15
        break

print(rs)







