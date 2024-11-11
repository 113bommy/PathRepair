from bisect import *

def binary_search_int(ok, ng, test):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if test(mid):
            ok = mid
        else:
            ng = mid
    return ng

def get_count1(k, A):
    """ K番目の要素が正の場合 """
    l, r = 0, len(A)-1
    res = 0
    while l < r:
        if A[l]*A[r] > k:
            r -= 1
            continue
        res += r-l
        l += 1
    return res

def get_count2(k, B, C):
    """ K番目の要素が負の場合 """
    l, r = 0, len(C)-1
    res = 0
    while True:
        if l > len(B)-1 or r < 0:
            break
        if B[l]*C[r] < -k:
            l += 1
            continue
        res += len(B)-l
        r -= 1
    return res

def test1(k):
    return get_count1(k, B) + get_count1(k, C) + count_negative < K

def test2(k):
    return get_count2(k, B, C) < K


N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

at_zero = bisect_left(A,0)
B = A[:at_zero]
B = list(map(lambda x: -x, B))
B = list(reversed(B))   # 負の要素
C = A[at_zero:]         # 正の要素
count_positive = (len(B)*(len(B)-1)//2 + len(C)*(len(C)-1)//2)
count_negative = N*(N-1)//2 - count_positive
if K > count_negative:
    print(binary_search_int(-1, 10**18+1, test1))
else:
    print(binary_search_int(-10**2, 1, test2))
