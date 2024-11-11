input()
l = [*map(int,input().split())]
l.sort()
if l[0] == l[-1]:
    print(-1)
else:
    print(*l)