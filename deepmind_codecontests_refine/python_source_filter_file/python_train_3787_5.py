n, t = map(int, input().split())
s = list(input())
a = []

temp = ''
i = 0
while i<t:
    j = n-1
    while j>0:
        if s[j]=='G' and s[j-1]=='B':
            a.append(j)
        j -= 1
    for b in a:
        s[j] = 'B'
        s[j-1] = 'G'
    i += 1

for c in s:
    print(c, end='')