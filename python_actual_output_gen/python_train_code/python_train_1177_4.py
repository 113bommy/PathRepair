X, Y, A, B, C = map(int, input().split())
P = sorted([int(i) for i in input().split()], reverse=True)
Q = sorted([int(i) for i in input().split()], reverse=True)
R = sorted([int(i) for i in input().split()])


S = sorted(P[:X]+Q[:Y]+R, reverse=True)
ans = sum(S[:X+Y])
