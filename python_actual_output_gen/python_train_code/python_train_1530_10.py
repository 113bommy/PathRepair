n, m = input().split()
n = int(n)
m = int(m)
desk = [[] for _ in range(n)]

for i in range(n):
    desk[i] = input()

c = []

for i in range(n):
    if '*' in desk[i]:
        c.append([i,desk[i].find('*')])
        if [i, desk[i].rfind('*')] not in c:
            c.append([i, desk[i].rfind('*')])

x = [item[0] for item in c]
y = [item[1] for item in c]
    
xt = 0
yt = 0

for item in x:
    if x.count(item) == 1:
        xt = item

for item in y:
    if x.count(item) == 1:
        yt = item

print(xt + 1, yt + 1)
