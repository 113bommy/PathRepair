n = int(input())
a = sorted(map(int, input().split()))
lst = -1
max_ans = n
for x in a:
    if lst < x-1:
        lst = x-1
    elif lst < x:
        lst = x
    elif lst < x+1:
        lst = x+1
    else:
        max_ans -= 1

a = sorted(set(a))
min_ans = 0
while a:
    min_ans += 1
    cur = a.pop()
    if a and a[-1] == cur-1:
        a.pop()
        if a and a[-1] == cur-2:
            a.pop()

print(min_ans, max_ans)
