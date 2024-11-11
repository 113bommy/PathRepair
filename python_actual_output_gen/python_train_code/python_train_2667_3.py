n = int(input())
tree = [0] * (n+1)
for i in range(n-1):
    vex1, vex2= map(int,input().split())
    tree[vex1] += 1
    tree[vex2] += 1
ans = 0
for i in range(n):
    if tree[i] == 1:
        ans += 1
print(ans)
