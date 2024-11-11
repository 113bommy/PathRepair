A, B, C, X, Y = map(int, input().split())

print(mix(X, Y) * 2 * C + (A if X > Y else B) * abs(X-Y), A * X + B * Y, max(X, Y) * 2 * C)