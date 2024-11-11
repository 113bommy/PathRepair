n = int(input())
a = []

for i in range(n):
    a.append(list(map(int, input().split())))

for i in a:
    if i[0] < i[1] + i[2] or sum(i) % 2:
        print("NO")
        exit()

print("YES")