H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
a = list(zip(*[i for i in a if "#" in a]))
a = list(zip(*[i for i in a if "#" in a]))
for i in range(len(a)):
    print("".join(a[i]))