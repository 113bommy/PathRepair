from sys import stdin

def bin_search(A, val) -> int:
    '''Returns position of value in sorted list A
       or -1 if value doesn't exist'''
    left_b = 0
    right_b = len(A)-1
    while left_b < right_b:
        mid = (left_b + right_b) >> 1
        if A[mid] > val:
            right_b = mid - 1
        elif A[mid] < val:
            left_b = mid + 1
        else:
            return mid
    ans = right_b if A[right_b] == val else -1
    return ans

def print_ans(ans) -> None:
    print(len(ans))
    print(*ans)

def main() -> None:
    #input
    n = int(input())
    A = [int(i) for i in stdin.readline().split()]
    A.sort()

    #init values
    max_gap = abs(A[-1] - A[0])
    if max_gap == 0:
        max_gap = 1
    ans = []
    gap = 1
    temp = []
    while gap <= max_gap:
        for a in A:
            #update temp
            temp.clear()
            temp.append(a)
            #since b = a+2^k, c = a+2^(k+1)
            b = a+gap
            c = b+gap

            #if b or c in list, add to the temp
            if bin_search(A, b) > -1:
                temp.append(b)
            if bin_search(A, c) > -1:
                temp.append(c)

            #update ans
            ans = max(ans, temp, key=len)

            if len(ans) == 3:
                print_ans(ans)
                return
        gap <<= 1
    print_ans(ans)
    
main()
