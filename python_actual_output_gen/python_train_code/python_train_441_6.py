def swap(A,i,j):
    A[i],A[j] = A[j],A[i]
    return A

def partition(A,p=0, r=None):
    if r is None:
        r = len(A)-1
    x = A[r]
    i = p-1
    for j in range(p,r):
        while A[j] <= x:
            i += 1
            swap(A,i,j)
    swap(A,i+1,r)
    return i+1

if __name__ == "__main__":
    input()
    A = list(map(int, input().strip().split()))
    k = partition(A)
    B = list(map(str, A))
    B[k] = "[{}]".format(B[k])
    print(" ".join(B))