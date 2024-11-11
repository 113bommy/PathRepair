n = int(input())
brackets_plus = []
brackets_minus = []
right = 0
left = 0
for i in range(n):
    s = input()
    cur = 0
    m = 0
    for j in range(len(s)):
        if s[j] == "(":
            left += 1
            cur += 1
        else:
            right += 1
            cur -= 1
            m = min(m,cur)
    if cur >= 0:
        brackets_plus.append((m,cur))
    else:
        brackets_minus.append((m,cur,m-cur))
if right != left:
    print("No")
    exit()
cur = 0
brackets_plus.sort(reverse = True)
for i in brackets_plus:
    if i[0] + cur < 0:
        print("No")
        exit()
    cur += i[1]
brackets_minus.sort(key = lambda x:x[2])
for i in brackets_minus:
    if i[0] + cur < 0:
        print("No")
        exit()
    cur += i[1]
print("Yes")