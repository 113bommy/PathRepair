n = int(input())
a = []
for i in range(n):
    s = input()
    a.append(s)
    if i < 2 :
        continue
    for j in range(n-2):
        if (a[i-1][j:j+3] == '...') and (a[i-2][j+1] == '.') and (a[i][j+1] == '.'):
            a[i-2] = a[i-2][:j+1] + '#' + a[i-2][j+2:]
            a[i-1] = a[i-2][:j] + '###' + a[i-1][j+3:]
            a[i] = a[i][:j+1] + '#' + a[i][j+2:]

out = 'YES'
for i in range(n):
    if a[i].find('.') > -1:
        out = 'NO'


print(out)

    
