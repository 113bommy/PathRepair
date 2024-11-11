n = int(input())
cnt = 0
a = 0
b = 0
both = 0
for i in range(n):
    s = input()
    cnt += s.count('AB')
    if s[0] == 'B':
        b += 1
    if s[-1] == 'A':
        a += 1
    if s[0] == 'B' and s[-1] == 'A':
        both += 1
if both == a and both != 0:
    print(cnt+both-1)
else:
    print(cnt+min(a,b))