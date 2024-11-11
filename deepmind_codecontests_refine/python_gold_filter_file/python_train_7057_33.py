S = list(input())
K = int(input())
R = []
hoge = 1
for i in range(1,len(S)):
    if S[i] == S[i-1]:
        hoge += 1
    else:
        R.append(hoge)
        hoge = 1
R.append(hoge)
ans = 0
if len(R) == 1:
    print((R[0]*K)//2)
    exit()
if S[0] == S[-1]:
    ans += (K-1)*((R[0]+R[-1])//2) + R[0]//2 + R[-1]//2
    R[0],R[-1] = 0,0
for i in R:
    ans += (i//2)*K 
print(ans)
