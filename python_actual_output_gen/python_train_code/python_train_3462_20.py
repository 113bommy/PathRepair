n = int(input())
ans = "NO"
for i in range(n):
    tri_num = i*(i+1)/2
    if tri_num < n:
        continue;
    if tri_num == n:
        ans = "YES"
    break

print(ans)