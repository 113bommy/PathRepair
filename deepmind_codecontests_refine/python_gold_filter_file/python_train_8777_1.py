def solve():
    n, a, b = [int(s) for s in input().split(" ")]
    if a == 1:
        if n%b == 1 or b==1:
            print("Yes")
        else:
            print("No")
        return
    p = 1
    while p <= n:
        if b==1 or n%b == p%b:
            print("Yes")
            return
        p *= a
    print("No")

t = int(input())
for _ in range(t):
    solve()