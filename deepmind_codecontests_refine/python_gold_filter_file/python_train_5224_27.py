N = int(input())
a = input()
s = ['0'] * 10

for i in range(N):
    if a[i] == 'R':
        for j in range(9, -1, -1):
            if s[j] == '0':
                s[j] = '1'
                break
    elif a[i] == 'L':
        for j in range(N):
            if s[j] == '0':
                s[j] = '1'
                break
    else:
        s[int(a[i])] = '0'

print(''.join(s))