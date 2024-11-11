def merge(A, B):
    Res = []
    i = 0
    j = 0
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            Res.append(A[i]) 
            i += 1 
        else:
            Res.append(B[j]) 
            j += 1 
    Res += A[i:] + B[j:] 
    return Res
def MergeSort(A): 
    if len(A) <= 1: 
        return A 
    else:
        L = A[:len(A) // 2] 
        R = A[len(A) // 2:] 
    return merge(MergeSort(L), MergeSort(R))
n=int(input())
A=list(map(int,input().split()))
A=MergeSort(A)
if n==2:
  print(min(A))
elif n%2==0:
  print(A[n//2])
else:
  print(A[(n-1)//2])

