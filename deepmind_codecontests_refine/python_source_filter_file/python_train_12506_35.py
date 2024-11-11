import heapq
n =int(input()) #map(int, input().split())
for i in range(n):
    m = int(input())
    s = input()
    if len(s) == 2 and s[0] <= s[1]:
        print('NO')
    else:
        print('YES')
        print('2')
        print(f'{s[0]} {s[1:]}')
