n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
team = list(set(a))
if len(team) >= k:
    print("YES")
    for i in range(3):
        print(a.index(team[i])+1, end=" ")
else:
    print("NO")
