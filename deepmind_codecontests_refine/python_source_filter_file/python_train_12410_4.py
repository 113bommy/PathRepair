n = int(input())
for i in range(n):
    n, n, m = map(int, input().split())
    print('YES' if sum(map(int, input().split())) >= sum(map(int, input().split())) else 'NO')
