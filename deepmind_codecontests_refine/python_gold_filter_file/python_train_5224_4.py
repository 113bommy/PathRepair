n = int(input())
m = input()
a = ['0'] * 10
for i in range(n):
    if m[i] == 'L':
        a[a.index('0')] = '1'
    elif m[i] == 'R':
        a[9 - a[::-1].index('0')] = '1'
    else:
        a[int(m[i])] = '0'
print(''.join(a))
