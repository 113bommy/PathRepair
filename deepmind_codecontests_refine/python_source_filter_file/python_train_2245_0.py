ls, j = list(map(int, input().split()))
inp = input()
g = inp.index('G')
t = inp.index('T')
for i in range(min(g,t), max(g,t), j):
    if inp[i] == "#":
        print("NO")
        break
    if inp[i] == inp[max(g,t)]:
        print("YES")
        break
else:
    print("NO")