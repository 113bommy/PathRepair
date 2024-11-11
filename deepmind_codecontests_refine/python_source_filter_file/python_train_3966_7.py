n, m = map(int, input().split())

for _ in range(m):
    input()

for _ in range(m // 2):
    print('01', end='')
    
if m % 2 == 1:
    print('0')