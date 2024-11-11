n, m = map(int, input().split())
a = [int(x) for x in input().split()]
a.insert(0, 0)
ans = [1]
check_table = [0]*(10**5+1)
check_table[a[n]] = 1
for i in range(n-1):
    if check_table[a[n-i-1]]:
        ans.append(ans[-1])
    else:
        check_table[a[n-i-1]] = 0
        ans.append(ans[-1]+1)
ans.reverse()
for i in range(m):
    print(ans[int(input())-1])