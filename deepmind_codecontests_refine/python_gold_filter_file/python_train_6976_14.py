def bubbleSort(C1,N):
    for i in range(N):
        for j in range(N-1,i,-1):
            if C1[j][1] < C1[j-1][1]:
                C1[j],C1[j-1] = C1[j-1],C1[j]
    return C1[:]
    
def selectSort(C2,N):
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if C2[minj][1] > C2[j][1]:
                minj = j
        C2[i],C2[minj] = C2[minj],C2[i]
    return C2[:]

N = int(input())
C1 = input().split()
C2 = C1[:]

C1 = bubbleSort(C1,N)
C2 = selectSort(C2,N)

print(*C1)
print("Stable")
print(*C2)
if C1 == C2:
    print("Stable")
else:
    print("Not stable")
