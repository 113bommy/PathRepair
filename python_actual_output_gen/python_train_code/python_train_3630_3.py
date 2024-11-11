n, m = list(map(int, input().split()))
h = input()
v = input()
if '<' in h and '>' in h and 'v' in v and '^' in v:
    if (h[0] == '<' and v[0] == '^') or (h[-1] == '>' and v[-1] == 'v') or (h[0] == '>' and v[-1] == '^') or (h[-1] == 'v' and v[0] == 'v'):
        print('NO')
    else:
        print('YES')
else:
    print('NO')