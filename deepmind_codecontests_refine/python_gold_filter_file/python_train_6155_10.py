def run(n, x, y):
    w_move = max(x-1, y-1)
    b_move = max(n-x, n-y)
    return "White" if w_move <= b_move else "Black"


n = int(input())
x, y = map(int, input().split())
print(run(n, x, y))
