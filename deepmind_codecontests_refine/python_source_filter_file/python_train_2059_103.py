a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

print('YES' if (b-a)-(v-w)*t <= 0 else 'NO')