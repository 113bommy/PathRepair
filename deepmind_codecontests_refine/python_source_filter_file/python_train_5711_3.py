S = input()
T = input()
q = int(input())
L = [[int(l) for l in input().split()] for _ in range(q)]

sumS = [0]*(len(S)+1)
sumT = [0]*(len(T)+1)

for i in range(len(S)):
    if S[i] == "A":
        sumS[i+1] += 1
    sumS[i+1] += sumS[i]

for i in range(len(T)):
    if T[i] == "A":
        sumT[i+1] += 1
    sumT[i+1] += sumT[i]

for i in range(q):
    a = (sumT[L[i][3]]-sumT[L[i][2]-1]) - (sumS[L[i][1]]-sumS[L[i][0]-1])
    b = (L[i][3]-L[i][2]+1) - (L[i][1]-L[i][0]+1) - a
    if (a-b)%3 == 0:
        print("Yes")
    else:
        print("No")