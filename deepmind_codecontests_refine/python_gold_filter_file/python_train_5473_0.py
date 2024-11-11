from sys import stdin, stdout, exit
 
n, m, k = map(int, stdin.readline().split())
d = 1 if stdin.readline()[6] == 'l' else -1
m = 1 if m < k else n
 
for i, c in enumerate(stdin.readline(), 1):
    if c == '0':
        if k == 1: k, d = 2, 1
        elif k == n: k, d = n - 1, -1
        else: k += d
        if m == k:
            stdout.write('Controller ' + str(i))
            exit(0)
    else:
        if k == 1: k, d, m = 2, 1, 1
        elif k == n: k, d, m = n - 1, -1, n
        elif d == 1:
            k += 1
            m = 1
        else:
            k -= 1
            m = n
 
stdout.write('Stowaway')