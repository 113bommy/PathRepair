from collections import deque, defaultdict, Counter
from bisect import bisect_left, bisect #bisect(list, num, beg, end)
import math
def test_case():
    inf = list(map(int, input().split()))
    n, k = inf
    a = list(map(int, input().split()))
    peaks = []
    curr = 0
    ans = 0
    l = 0
    for i in range(2, n):
        if i >= k:
            if a[i - k] < a[i-k+1] > a[i-k+2]:
                curr -= 1
        if a[i-2] < a[i-1] > a[i]:
            curr += 1
        # print(i, curr)
        if ans < curr and i >= k - 1:
            ans = curr
            l = i - k + 2
    # print(peaks)
    # i = 0
    # j = 0
    # ans = 0
    # l = -1
    # while j < len(peaks) and i <= j:
    #     while j + 1 < len(peaks) and peaks[j+1] - peaks[i] + 3 <= k:
    #         j += 1
    #     # print((i, j), (peaks[i], peaks[j]))
    #     if j < len(peaks) and ans < j - i + 1 and peaks[j] - peaks[i] + 3 == k:
    #         ans = j - i + 1
    #         l = peaks[i]
    #     while i + 1 <= j and peaks[j] - peaks[i+1] + 3 >= k:
    #         i += 1
    #     if j < len(peaks) and ans < j - i + 1 and peaks[j] - peaks[i] + 3 == k:
    #         ans = j - i + 1
    #         l = peaks[i]
    print(ans+1, l)
for _ in range(int(input())):

    ret = test_case()
    if ret:
        print(ret)
