N, M, X, Y = map(int, input().split())
x = max(map(int, input().split()))
y = min(map(int, input().split()))
if x < y and x < Y and X < y:
    print("No War")
else:
    print("War")
