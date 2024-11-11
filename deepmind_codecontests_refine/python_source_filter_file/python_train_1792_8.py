res = 0
s = input()
 
m = [['F',1]]
m.clear()
m.append([s[0], 0])
k = 0
for i in s:
    if m[k][0] == i:
        m[k][1] += 1
    else:
        m.append([i, 1])
        k+=1
k = len(m)
if( (k % 2 == 1) and (m[k//2][1] > 1)):
    res = m[k//2 + 1][1] + 1
    for i in range(k//2):
        if not (( m[i][0] == m[k - i - 1][0]) and (m[i][1] + m[k - i - 1][1]) > 2):
            res = 0
            break
print (res)
