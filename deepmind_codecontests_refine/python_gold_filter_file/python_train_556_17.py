from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

arr = []
res=0
for _ in range(3):
    t = iia()
    res += sum(t)
    arr.append(t)
res //= 2
arr[0][0] = res - arr[0][1] - arr[0][2]
arr[1][1] = res - arr[1][0] - arr[1][2]
arr[2][2] = res - arr[2][0] - arr[2][1]
for i in arr:
    print(*i,sep=" ")
    
