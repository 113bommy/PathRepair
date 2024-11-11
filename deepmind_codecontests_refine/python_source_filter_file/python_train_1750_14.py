 
def solve():
    H,W,N= [int(x) for x in input().split()]
     
    Sr,Sc = [int(x) for x in input().split()]
     
    S = input()
    T = input()
     
    minu = Sr
    maxd = Sr
    maxr = Sc
    minl = Sc
    for i in range(N):
        if S[i] == 'U':
            minu -= 1
            if minu == 0:
                return "NO"
        if S[i] == 'D':
            maxd += 1
            if maxd == H+1:
                return "NO"
        if S[i] == 'R':
            maxr += 1
            if maxr == W+1:
                return "NO"
        if S[i] == 'L':
            minl -= 1
            if minl == 0:
                return "NO"
 
        if T[i] == 'D' and minu < W:
            minu += 1
        if T[i] == 'U' and maxd > 1:
            maxd -= 1
        if T[i] == 'L' and maxr > 1:
            maxr -= 1
        if T[i] == 'R' and minl < H:
            minl += 1
 
    return "YES"
 
print(solve())
