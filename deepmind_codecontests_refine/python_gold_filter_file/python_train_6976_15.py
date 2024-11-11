N=int(input())
A=input().split()

B=A[:]
S=A[:]

def BubbleSort(A, N):
    count = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j][1] < A[j-1][1]:
                A[j], A[j-1] = A[j-1], A[j]
                count += 1
                flag = True
                
    return A

def SelectionSort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j][1] < A[minj][1]:
                minj = j
        A[i], A[minj] = A[minj], A[i] 
        count += 1
    return A

b = BubbleSort(B, N)
s = SelectionSort(S, N)
print(*b)
print("Stable")
print(*s)

if b == s:
    print("Stable")
else:
    print("Not stable")