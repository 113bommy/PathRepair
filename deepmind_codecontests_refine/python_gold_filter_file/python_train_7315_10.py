t = int(input())

def solve():
    n = int(input())
    cubes = list(map(int, input().split()))
    for i in range(1, n):
        if(cubes[i] >= cubes[i - 1]):
            print("YES")
            return
    print("NO")

for i in range(t):
    solve()
