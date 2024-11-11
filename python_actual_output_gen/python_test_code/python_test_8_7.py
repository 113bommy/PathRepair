t = int(input())
for i in range(t):
    s, a, b, c = map(int, input().split(' '))
    print((s // (c * a)) * a, (s // (c * a)) * b, int((s - (s // (c * a)) * a * c)/c))
