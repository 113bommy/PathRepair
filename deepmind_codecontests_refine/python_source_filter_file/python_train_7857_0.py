n = int(input())
a = []
for i in range(n):
    a.append(input())
ans = 0
for i in range(n):
    cur_ans = 0
    for j in range(n):
        if a[i] == a[j]:
            cur_ans += 1
    ans = max(ans, cur_ans - 1)
print(ans)