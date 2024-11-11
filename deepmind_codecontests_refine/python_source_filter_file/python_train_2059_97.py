a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

ans = "NO"
if (v-w)*t >= (b-a):
    ans = "YES"

print(ans) 