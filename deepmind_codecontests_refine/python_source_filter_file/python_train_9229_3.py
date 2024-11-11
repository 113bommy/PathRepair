n,k = [int(x) for x in input().split()]

print("YES")
ans = [["." for _ in range(n)] for _ in range(4)]
if k%2 == 0:
    c = 1
    while k > 0:
        ans[1][c] = "#"
        ans[2][c] = "#"
        c += 1
        k -= 2
else:
    c = 0
    m = (n-1)//2
    while k > 0 and c < m:
        ans[1][m+c] = "#"
        k -= 1
        if c != 0 :
            ans[1][m-c] = "#"
            k -= 1
        c += 1
    if k > 0:
        ans[2][1] = "#"
        ans[2][n-2] = "#"
        k -= 2
    c = 1
    while k > 0:
        ans[2][c] = "#"
        k -= 1
        c += 1

for line in ans:
    print("".join(line))
        
