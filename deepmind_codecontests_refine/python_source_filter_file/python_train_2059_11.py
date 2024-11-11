a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())
d = abs(b-a)
d2 = w-v
print('YES' if d <= d2*t else 'NO')