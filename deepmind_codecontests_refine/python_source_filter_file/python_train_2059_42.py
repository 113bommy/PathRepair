a, v = [int(x) for x in input().split()]
b, w = [int(x) for x in input().split()]
t = int(input())

print('YES' if abs(a-b) < (v-w)*t else 'NO')