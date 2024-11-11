n, m = map(int, input().split())
a = [int(x) for x in input().split()]
a.insert(0, 0)
ans = [1]
ans_temp = 1
set1 = set()
for i in range(n):
    if a[n-i] not in set1:
        ans_temp += 1
        set1.add(a[n-i])
    ans.append(ans_temp)
ans.reverse()
for i in range(m):
    print(ans[int(input())-1])