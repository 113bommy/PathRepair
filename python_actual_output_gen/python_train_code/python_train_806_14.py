a, b, c, d = map(int, input().split())
# A = list(map(int, input().split()))
# a = int(input())
if a <= b <= c or a >= b >= c:
    print(max(d - abs(a - b), 0) - max(d - abs(c - b), 0))
elif a <= c <= b or a >= c >= b:
    print(max(d - abs(a - c), 0) - max(d - abs(c - b), 0))
else:
    print(max(d - abs(a - c), 0) - max(d - abs(a - b), 0))
