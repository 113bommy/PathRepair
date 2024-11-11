a = [list(map(int, input().split())) for _ in range(3)]
n = int(input())
b = [int(input()) for _ in range(n)]

bingo = 'No'

for t in zip(*a):
    a.append(list(t))

a.append([a[i][i] for i in range(3)])
a.append([a[i][2-i]for i in range(3)])

for line in a:
    if all(item in b for item in a):
        bingo = 'Yes'

print(bingo)

