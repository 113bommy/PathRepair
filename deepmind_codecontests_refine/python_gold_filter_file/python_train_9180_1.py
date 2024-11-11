n = int(input())
s = list(input())

if n % 2 == 1 or s.count('(') != s.count(')'):
    print('0\n1 1')
    exit()

def solve():
    cnt_open, res, need = 0, 0, 0
    for i in s:
        if i == '(':
            cnt_open += 1
        else:
            cnt_open -= 1
            if cnt_open < need:
                need = cnt_open
                res = 1
            elif cnt_open == need:
                res += 1
    return res

res, res_i, res_j = solve(), 0, 0
for i in range(n):
    for j in range(i+1, n):
        if s[i] != s[j]:
            s[i], s[j] = s[j], s[i]
            curr = solve()
            s[i], s[j] = s[j], s[i]
            if curr > res:
                res = curr
                res_i = i
                res_j = j
print(res)
print(res_i+1, res_j+1)
