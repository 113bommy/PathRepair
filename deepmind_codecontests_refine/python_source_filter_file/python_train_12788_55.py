A,B,C,D,E,F = map(int,input().split())
ans = ["0","0"]
M = 0
for a in range(31):
    if F < a*A*100:
        break
    for b in range(31-a):
        if a == 0 and b == 0:
            continue
        W = (a*A+b*B)*100
        if F < W:
            break
        CD_max = min((E * W) // 100,F-W)
        for c in range(CD_max//C+1):
            d = max(0,(CD_max-c*C)//D)
            CD = c*C+d*D
            con = CD/(W+CD)
            if con > M:
                M = con
                ans = [str(W+CD),str(CD)]
print(" ".join(ans))