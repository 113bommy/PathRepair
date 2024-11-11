from collections import Counter
t = int(input())
cnt = 0
while (cnt < t):
    cnt += 1
    s = input()
    tot = len(s)
    s = Counter(s)
    a = s.most_common(1)
    if a[0][0] == 'R':
        print('P' * tot)
    elif a[0][0] == 'S':
        print('R' * tot)
    else:
        print('S' * tot)