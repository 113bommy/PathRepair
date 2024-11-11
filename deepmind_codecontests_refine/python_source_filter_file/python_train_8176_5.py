# You lost the game.
s = str(input())
n = len(s)
A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
if n < 26:
    print(-1)
else:
    for i in range(n-25):
        ok = 1
        F = [0 for _ in range(26)]
        for j in range(26):
            if s[i:i+26].count(A[j]) > 1:
                ok = 0
                break
            elif s[i:i+26].count(A[j]) == 0:
                F[j] = 1
        if ok:
            break
    if ok == 0:
        print(-1)
    else:
        j = 0
        for k in range(n):
            if s[k] == "?":
                if k >= i and k < i+26:
                    while F[j] == 0:
                        j += 1
                    print(A[j],end="")
                    F[j] = 0
                else:
                    print(A,end="")
            else:
                print(s[k],end="")
            
