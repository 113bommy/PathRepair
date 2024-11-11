a=input()
b=input()
c=input()

X=[a,b,c]
LEN=[len(a),len(b),len(c)]

MF=[[[1]*2001 for j in range(3)] for i in range(3)]

for i in range(3):
    for j in range(3):
        if i==j:
            continue
        for k in range(2001):
            for l in range(LEN[j]):
                if k+l>=LEN[i]:
                    break
                if X[i][k+l]!="?" and X[j][l]!="?" and X[i][k+l]!=X[j][l]:
                    MF[i][j][k]=0
                    break

ANS=1000000
for i in range(3):
    for j in range(3):
        if i==j:
            continue
        for k in range(2001):
            if MF[i][j][k]==1:
                for l in range(2001):
                    if ANS<=max(LEN[i],LEN[j]+k,LEN[3-i-j]+k+l):
                        break
                    if MF[j][3-i-j][l]==1 and (k+l>2000 or MF[i][3-i-j][k+l]==1):
                        ANS=max(LEN[i],LEN[j]+k,LEN[3-i-j]+k+l)

print(ANS)
