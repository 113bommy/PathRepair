n = int(input())
k = input().strip()
ans1 = 0
ans2 = 0
cnt1 = 0
cnt2 = 0
_in = 0
p = '_'
for i in k:
    if _in:
        if i == ')':
            _in = 0
        if ((i == '_' or i == ')') and (p != '_' and p != '(')):
            ans2 += 1
        p = i
    else:
        if (i == '('):
            if (p != '_' and p != ')'):
                ans1 = max(ans1, cnt1)
            cnt1 = 0
            _in = 1
        elif (i == '_' and p != '_' and p != ')'):
            ans1 = max(ans1, cnt1)
            cnt1 = 0
        elif (i != '_'):
            cnt1 += 1
        p = i
print(ans1, ans2)

