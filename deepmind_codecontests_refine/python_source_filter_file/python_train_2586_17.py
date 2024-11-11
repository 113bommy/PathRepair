N = int(input())
list = [int(input()) for i in range(n)]
c = 0
x = 1
while x != 2 and c < N:
    x = list[x - 1]
    c += 1
if x == 2:
    print(c)
else:
    print(-1)
