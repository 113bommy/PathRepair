def FilyasHW(n, arr):
    S = list(set(arr))
    S.sort()
    if n < 3 or len(S) < 3:
        return True
    
    if len(S) > 3:
        return False
    D = {}
    for i in arr:
       D[i] = D.get(i, 0) + 1

    if S[1] - S[0] == S[2] - S[1]:
        return True
    else:
        return False

n = int(input())
arr = [int(i) for i in input().split()]

if FilyasHW(n, arr):
    print("YES")
else:
    print("NO")
    
