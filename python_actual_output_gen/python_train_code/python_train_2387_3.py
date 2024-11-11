
t = input()
x, y, d = '', '', '.00'
if t[0] == '-': x, y = '(', ')'
k = t.find('.')
if k > 0: d = (t[k: ] + '00')[: 3]
else: k = len(t)
j = len(x)
u = t[j: j + (k - j) % 3]
j += len(u)
if u and k > j: u += ','
 
print(x + '$' + u + ','.join(t[i: i + 3] for i in range(j, k, 3)) + d )