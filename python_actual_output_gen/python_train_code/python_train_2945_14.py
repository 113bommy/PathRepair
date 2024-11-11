from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

tc = ii1()
for _ in range(tc):
    x, n, m = iia()
    while n and x>20:
        x = (x // 2)+10
        n -= 1
    while m and x>0:
        x -=10
        m -= 1
    if x:
        print("NO")
    else:
        print("YES")
        