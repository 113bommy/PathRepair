n, m = map(int, input().split())
let = []

l = m
r = 0
fl1 = 0
fl2 = n

for i in range(n):
    s = input()
    let.append(s)
    
    if '*' in s:
        if fl1 == 0:
            fl1 = i
            
        if s.index('*') < l:
            l = s.index('*')

        if m - s[::-1].index('*') - 1 > r:
            r = m - s[::-1].index('*') - 1

for item in let[::-1]:
    if '*' not in item:
        fl2 -= 1
    else:
        break
    
for i in range(fl1-1, fl2):
    for j in range(l, r):
        print(let[i][j], end = '')
    print()
