a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

if b - a < (v-w)*t:
    print("YES")
else:
    print("NO")
