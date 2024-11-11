N, M, X, Y = map(int,input().split())
x = max(map(int, input().split()))
y = min(map(int, input().split()))
print("No War" if x < y and X < y and x < Y else "War")