#In the name of Allah

from sys import stdin, stdout
input = stdin.readline

r, s = map(int, input().split())
cake = [list(input()) for _ in range(r)]

for i in range(r):
    if not "S" in cake[i]:
        cake[i] = ["#"] * s
for i in range(s):
    f = False
    for j in range(r):
        if cake[j][i] == "S":
            f = True
    if not f:
        for j in range(r):
            cake[j][i] = "#"

ans = 0
for i in cake:
    ans += i.count("#")
        
stdout.write(str(ans))
