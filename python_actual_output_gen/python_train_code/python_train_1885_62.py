def solve():
    l,r=[int(x) for x in input().split()]
    if l//r >= l//2:
        print("YES")
    else:
        print("NO")
t=int(input())
for i in range(t):
    solve()