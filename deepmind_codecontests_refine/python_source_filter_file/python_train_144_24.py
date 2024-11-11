m = int(input().split()[1])

yarmarka = [int(x) for x in input().split()]

c = 0
d = 0
for i in range(len(yarmarka)-1):
    d = (yarmarka[i] - yarmarka[i+1])
    if d >= c:
        c = d
if c == 0:
    print(c)
else:
    print(c - m)