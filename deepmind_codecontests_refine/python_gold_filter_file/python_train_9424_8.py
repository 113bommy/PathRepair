n = int(input())

S = [int(x) for x in input().split()]

S.sort()

T = [S[0]]
t = 0
check = True
S[0] = 0
total = 1
while total < len(S):
    for j in range(1,len(S)):
        if S[j] > T[-1]:
            T.append(S[j])
            S[j] = 0
            total += 1
            t += 1
            break
    else:
        for i in range(len(S)):
            if S[i] != 0:
                T.append(S[i])
                S[i] = 0
                total += 1
                break
print(t)