t = int(input())
for _ in range(t):
    n, k1, k2 = [int(i) for i in input().split()]
    a = (int(i) for i in input().split())
    b = (int(i) for i in input().split())
    print('YES' if sum(a) > sum(b) else 'NO')