n, k = map(int, input().split(' '))
t = input()

s = set()
for c in t:
    s.add(c)
if len(s) == 1:
    print(t, end='')
    for i in range(k-1):
        print(t[0], end='')
    print('')
else:
    # Get the longest prefix that is also suffix
    suffixsize = 0
    for i in range(n - 1, 0, -1):
        if t[:i] == t[-i:]:
            suffixsize = i
            break
    if suffixsize > 0:
        print(t, end='')
        for i in range(k - 1):
            print(t[-(n-suffixsize):], end='')
        print('')
    else:
        for i in range(k):
            print(t, end='')
        print('')
