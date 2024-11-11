n = int(input())
e = []
for i in range(n):
    e.append(input().split())
print(e)
for i in range(n):
    if e[i][1] == 'rat':
        print(e[i][0])
for i in range(n):
    if e[i][1] == 'woman' or e[i][1] == 'child':
        print(e[i][0])
for i in range(n):
    if e[i][1] == 'man':
        print(e[i][0])
for i in range(n):
    if e[i][1] == 'captain':
        print(e[i][0])
