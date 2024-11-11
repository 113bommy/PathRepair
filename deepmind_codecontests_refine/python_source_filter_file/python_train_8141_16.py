t = int(input().strip())
# nums = list(map(int, input().strip().split()))
for _ in range(t):
    s = input().strip()
    l = len(s)
    count = 0
    ps = []
    for i, c in enumerate(s):
        if i == 0 or i == l-1:
            continue
        elif c == 'n' and s[i-1:i+2] == 'one':
            if s[i-3:i+2] != 'twone':
                ps.append(str(i))
                count += 1
        elif c == 'w' and s[i-1:i+2] == 'two':
            if s[i-3:i+2] != 'twone':
                ps.append(str(i))
                count += 1
            else:
                ps.append(str(i+1))
                count += 1
    print(count)
    print(' '.join(ps))
