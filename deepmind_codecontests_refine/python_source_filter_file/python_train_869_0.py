# Dynamic programming Python implementation
# of LIS problem

# lis returns length of the longest
# increasing subsequence in arr of size n
def lis(l, arr):
    # Declare the list (array) for LIS and
    # initialize LIS values for all indexes
    ls = [1] * l

    # Compute optimized LIS values in bottom up manner
    for i in range(1, l):
        for j in range(0, i):
            if arr[i] >= arr[j] and ls[i] < ls[j] + 1:
                ls[i] = ls[j] + 1
    # print(ls)
    return l - max(ls)


# end of lis function


n, m = map(int, input().split())
lst = []
for i in range(n):
    a, b = map(str, input().split())
    lst.append(a)

print(lis(n, lst))
