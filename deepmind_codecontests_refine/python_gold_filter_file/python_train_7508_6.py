s = input()
if len(s) == 1:
    print('Impossible')
    exit()
n = len(s)
m = len(s) // 2

def is_pal(s):
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            return False
    return True

for i in range(n):
    ns = s[i:] + s[:i]
    if n % 2 == 0:
        if is_pal(ns):
            if ns != s:
                print(1)
                exit()
    else:
        if is_pal(ns):
            if ns != s:
                print(1)
                exit()

if len(s) % 2 == 0:
    if s[:m] != s[m:]:
        print(1)
        exit()
    else:
        if len(set(s[:m])) == 1:
            print('Impossible')
            exit()
        print(2)
        exit()
else:
    if s[:m] != s[(m+1):]:
        print(2)
        exit()
    else:
        if len(set(s[:m])) == 1:
            print('Impossible')
            exit()
        print(2)
        exit()