n = int(input())
tree = list(map(int,input().split()))
colors = list(map(int,input().split()))

ans = 0
for i in range(1,n):
    if colors[i] != colors[tree[i-1]-1]:
        ans += 1
print(ans)