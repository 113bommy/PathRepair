n, p = map(int, input().split())
s = str(input())
t = [0]*n
for i in range(n):
    if s[i] != '.':
        t[i] = s[i]
    else:
        if i-p >= 0:
            t[i] = str(1-int(t[i-p]))
        else:
            if i+p <= n-1:
                if s[i+p] != '.':
                    t[i] = str(1-int(t[i+p]))
                else:
                    t[i] = '0'
            else:
                t[i] = '0'
#print(t)
flag = False
for i in range(n-p):
    if t[i] != t[i+p]:
        flag = True
if flag:
    print(''.join(t))
else:
    print('No')
