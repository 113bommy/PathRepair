g, f = list(map(int, input().split()))
a = list(map(int, input().split()))
team = list(set(a))
if len(team) >= f:
    print("YES")
    for i in range(f):
        print(a.index(team[i])+1, end=" ")
else:
    print("NO")
