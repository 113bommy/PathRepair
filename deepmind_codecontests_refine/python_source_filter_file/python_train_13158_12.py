n,k = map(int, input().split())

x = list(map(int, input().split()))

s  = [x[0]]
for i in range(1, n):
    s.append(x[i] + s[i-1])

max_sum = -1
max_b = -1
ans = [-1, -1]
cur_b = -1
for i in range(len(x)-2*k, -1,-1):
    new_b = s[i + 2*k - 1] - s[i +k]
    if new_b >= max_b:
        max_b = new_b
        cur_b = i+k+1
    a_val = s[i + k - 1]
    if i > 0:
        a_val -= s[i - 1]
    if a_val +max_b >= max_sum:
        max_sum = a_val +max_b
        ans[0] = i + 1
        ans[1] = cur_b

print(str(ans[0]) + ' '+ str(ans[1]))