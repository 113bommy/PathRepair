import sys
def single_input(F): return F.readline().strip("\n")
def line_input(F): return F.readline().strip("\n").split()
  
def solve():
    F = sys.stdin
    N = int(single_input(F))
    S = [int(s) for s in line_input(F)]
    
    maxpoint = 0
    for c in range(1, N//2):
        s, l = 0, N-1
        point = 0
        if N % c > 0:
            while l > s and l > c:
                point += S[s] + S[l]
                maxpoint = max(point, maxpoint)
                s += c
                l -= c
        else:
            while l != s and l > c:
                point += S[s] + S[l]
                maxpoint = max(point, maxpoint)
                s += c
                l -= c
    print(maxpoint)
    return 0
  
if __name__ == "__main__":
    solve()