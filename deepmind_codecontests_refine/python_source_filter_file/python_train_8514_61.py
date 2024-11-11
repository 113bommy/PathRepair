import bisect

s = input()
t = input()
n = len(s)
s0 = {}
for i in range(n):
    s0.setdefault(s[i], [])
    s0[s[i]].append(i)
num1 = 0
num2 = 0
flag = True
for i in t:
    if i not in s:
        flag = False
        break
    num = bisect.bisect_right(s0[i], num2)
    if num == len(s0[i]):
        num1 += 1
        num2 = s0[i][0]
    else:
        num2 = s0[i][num]
if flag == True:
    print(num1 * n + num2 + 1)
else:
    print(-1)