

def  maxHeapify(i):
    l =2*i
    r = 2*i+1
    # print(A[i])
    largest =0
    if l <=H and A[l]> A[i]:
        largest = l
    else:
        largest = i

    if r <= H and A[r] > A[largest]:
        largest = r

    if largest != i :
        A[i],A[largest] = A[largest],A[i]
        maxHeapify(largest)
    # print(A)



H = int(input())

A = list(map(int,input().split()))

A = [-1]+A

for i in range(int(H/2),0,-1):
    maxHeapify(i)

Astr = list(map(str,A))

# print(" ",end="")

print(*A[1:])