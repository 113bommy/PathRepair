import sys

def solve():
    input = sys.stdin.readline
    H, W, N = map(int, input().split())
    s, r = map(int, input().split())
    S = input().strip("\n")
    T = input().strip("\n")
    Lb, Rb, Ub, Db = -1, W, -1, H
    for i in reversed(range(N)):
        if i != N - 1:
            if T[i] == "L": Rb = min(Rb + 1, W)
            elif T[i] == "R": Lb = max(Lb - 1, -1)
            elif T[i] == "U": Db = min(Db + 1, H)
            elif T[i] == "D": Ub = max(Ub - 1, 0)

        if S[i] == "L": Lb = Lb + 1
        elif S[i] == "R": Rb = Rb - 1
        elif S[i] == "U": Ub = Ub + 1
        elif S[i] == "D": Db = Db - 1

        if Lb >= W - 1 or Rb <= 0 or Ub >= H - 1 or Db <= 0:
            print("No")
            break
    else:
        if Lb < r - 1 < Rb and Ub < s - 1 < Db: print("Yes")
        else: print("No")
    
    #print(Lb, Rb, Ub, Db)

    return 0

if __name__ == "__main__":
    solve()