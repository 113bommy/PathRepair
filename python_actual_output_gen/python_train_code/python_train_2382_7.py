s = input()
ls = len(s)
l1 = s.find('[')
r1 = ls - 1 - s[::-1].find(']')
if l1 == -1 or r1 == ls or l1 > r1:
    print(-1)
    exit(0)
l2 = s.find(':', l1+1, r1)
r2 = r1 - 1 - s[r1-1:l1:-1].find(':')
if l1 == -1 or r1 == ls or l2 == r2:
    print(-1)
    exit(0)
print(4 + s.count('|', l2+1, r2))
