def swap(A,i,j):
    A[i],A[j] = A[j],A[i]
    return A

def isStable(A):
    for i in range(1, len(A)):
        if A[i][1] == A[i-1][1]:
            if A[i][2] < A[i-1][2]:
                return False
    return True

def partition(A,p=0, r=None):
    if r is None:
        r = len(A)-1
    x = A[r]
    i = p-1
    for j in range(p,r):
        if A[j][1] <= x[1]:
            i += 1
            swap(A,i,j)
    swap(A,i+1,r)
    return i+1

def quick(A,p=0,r=None):
    if r is None:
        r = len(A)-1
    if p < r:
        q = partition(A,p,r)
        quick(A,p,q-1)
        quick(A,q+1,r)

import sys
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    A = []
    for i in range(n):
        card = sys.stdin.readline().split()
       A.append([card[0], int(card[1]), i])
    quick(A,0,n-1)
    if isStable(A):
        print("Stable")
    else:
        print("Not stable")
    for card in A:
        print(card[0], card[1])