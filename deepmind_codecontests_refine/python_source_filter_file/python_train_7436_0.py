n, k = map(int, input().split());
s = input();
if 2 * k <= n:
    for i in range(k): print('LEFT');
    way = 'RIGHT'
    print('PRINT', s[0])
    for i in range(1, len(s)):
        print(way);
        print('PRINT', s[i])
else:
    for i in range(n-k): print('RIGHT') ;
    way = 'LEFT'
    s = s[::-1];
    print('PRINT', s[0])
    for i in range(1, len(s)):
        print(way);
        print('PRINT', s[i]) 