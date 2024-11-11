import sys
input = sys.stdin.buffer.readline 

def process(A, k):
    n = len(A)
    A2 = sorted(A)
    next_dict= {}
    for i in range(n-1):
        next_dict[A2[i]] = A2[i+1]
    answer = 0
    for i in range(n-1):
        if A[i] in next_dict and A[i+1] != next_dict[A[i]]:
            answer+=1
        elif A[i]==A2[-1] and i != n-1:
            answer+=1
        if answer > k-1:
            return 'No'
    return 'Yes'

t = int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    print(process(A, k))