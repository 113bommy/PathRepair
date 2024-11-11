global A

def max_heapfy(i):
    left = 2*i+1
    right = 2*i+2

    max_val = 0
    if left< H and A[i] < A[left]:
        max_val = left
    else:
        max_val = i

    if right<H and A[max_val] < A[right]:
        max_val = right

    if max_val != i:
        temp = A[i]
        A[i] = A[max_val]
        A[max_val] = temp
        max_heapfy(max_val)

if __name__ == '__main__':
    global H
    H = int(input())
    A = [int(i) for i in input().split()]
    for i in reversed(range(H//2)):
        max_heapfy(i)

    for a in A:
        print(" {}".format(a),end='')
        print('')