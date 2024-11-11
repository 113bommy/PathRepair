s, v0, v1, p0, p1 = map(int, input().split())
if s * v0 + p0 + p0 > s * v1 + p1 + p1:
    print('First')
elif s * v0 + p0 + p0 < s * v1 + p1 + p1:
    print('Second')
else:
    print('Friendship')