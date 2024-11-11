n = int(input())

count = 3

home = []
visiting = []

for i in range(n):
    h, v = map(int,input().split())
    home.append(h)
    visiting.append(v)


for l in home:
    for k in visiting:
        if l == k:
            count += 1
print(count)