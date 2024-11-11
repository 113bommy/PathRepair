import math
def moves(n):
    sq = math.sqrt(n)
    if int(sq) != sq:
        sq = int(sq) + 1
    i = sq
    while i * sq >= n:
        i -= 1
    i += 1
    return int(i + sq - 2)

T = int(input())
for t in range(T):
    ans = moves(int(input()))
    print(ans)

