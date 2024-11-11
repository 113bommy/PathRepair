h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
for i in range(h):
    a = [j for j in a if "#" in j]
    a = list(map(list, (zip(*a))))
for i in a:
    print("".join(i))