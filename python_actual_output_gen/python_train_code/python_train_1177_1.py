X, Y, A, B, C = map(int, input().split())
*P, = map(int, input().split())
*Q, = map(int, input().split())
*R, = map(int, input().split())
P = sorted(P, reverse=True)[:X]
Q = sorted(Q, reverse=True)[:-Y]
print(sum(sorted(P + Q + R, reverse=True)[:-(X + Y)]))
