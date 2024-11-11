A, V = map(int, input().split())
B, W = map(int, input().split())
T = int(input())
print('YES' if (V - W) * T >= (B - A) else 'NO')
