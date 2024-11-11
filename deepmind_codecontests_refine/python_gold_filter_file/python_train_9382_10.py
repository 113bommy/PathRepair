n = int(input())
L = [int(x)%2 for x in input().split()]
S = []
temp = 1
LW = []
RW = []
Close = []
for i in range(1,n):
    if L[i] == L[i-1]:
        temp +=1
    else:
        S.append(temp)
        temp = 1
S.append(temp)
z = 0
for i in range(0,len(S)):
    S[i] = S[i]%2
    if S[i] == 0:
        z +=1
        LW.append(i)
        RW.append(len(S)-i-1)
        if len(LW) > 1:
            Close.append(LW[-1]-LW[-2])
        

index = 0
removed = 0
while index < z-1:
    if Close[index] <= LW[index] - removed:
        removed += 2*Close[index]
        index += 2
    else:
        removed += 2*(LW[index]-removed)+1
        index += 1

if index == z-1:
    if abs(LW[z-1]-removed- RW[z-1]) <= 1:
        print('YES')
    else:
        print('NO')
else:
    if removed >= len(S)-1:
        print('YES')
    else:
        print('NO')