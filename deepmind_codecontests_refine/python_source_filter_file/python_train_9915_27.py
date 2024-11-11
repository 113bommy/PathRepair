import math
t = int(input())

def solve(n, k, nums):
    pref_peaks = [0] * n

    for i in range(1, n - 1):
        if nums[i-1] < nums[i] > nums[i+1]:
            pref_peaks[i] = 1 + pref_peaks[i - 1]
        else:
            pref_peaks[i] = pref_peaks[i-1]

    pref_peaks[n-1] = pref_peaks[n-2]
    
    print(' '.join(list(map(str, pref_peaks))))

    mx = -1
    mx_i = -1

    for l in range(n - k + 1):
        r = l + k - 1

        if 0 > r  or r >= n:
            continue

        res = pref_peaks[r-1] - pref_peaks[l] + 1
        #print('between', l, 'and', r, ':', res)

        if res > mx:
            mx = res
            mx_i = l + 1
        
    return mx, mx_i

for _ in range(t):
    n, k = list(map(int,input().split()))
    nums = list(map(int, input().split()))
    res = solve(n, k, nums)
    print(res[0], res[1])