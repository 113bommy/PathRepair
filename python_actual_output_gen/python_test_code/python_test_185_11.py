n = int(input())
s - input()
cnt = 0
m = 0
for i in s:
    if i == ')':
        cnt += 1
    else:
        cnt -= 1
    m = max(m, cnt)
print('()'*m+s+')'*(m-cnt))