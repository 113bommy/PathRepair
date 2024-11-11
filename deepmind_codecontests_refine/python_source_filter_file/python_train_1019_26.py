N = int(input())
S = input()

A = [None]*(N+1)
A[0] = 0
cnt = 0
for i,s in enumerate(S[::-1]):
    if s=='.':
        A[i+1] = A[i]+1
    else:
        A[i+1] = A[i]-1
        cnt += 1
print(A)
print(min(A)+cnt)