from collections import defaultdict

def str2dict(s):
    dict_s = defaultdict(list)
    for i in range(len(s)):
        ch = s[i]
        dict_s[ch].append(i)
    return dict_s

def searchsorted(arr, x):
    l = 0
    r = len(arr)-1
    while r-l > 1: 
        mid = l + (r - l)//2; 
        # Check if x is present at mid 
        if arr[mid] == x: 
            return mid 
        # If x is greater, ignore left half 
        elif arr[mid] < x: 
            l = mid
        # If x is smaller, ignore right half 
        else: 
            r = mid
    if arr[r]==x:
        return r
    return l

def find_oper(dict_s, t):
    i_t = 0
    n_oper = 0
    while i_t<len(t):
        i_s = -1
        n_oper += 1
        while i_t<len(t):
            ch = t[i_t]
            if ch not in dict_s:
                return -1
            if dict_s[ch][-1] <= i_s:
                break
            i_s = dict_s[ch][searchsorted(dict_s[ch], i_s+1)]
            i_t += 1
    return n_oper

T = int(input())
out = [0]*T
for i in range(T):
    s = input()
    t = input()
    out[i] = str(find_oper(str2dict(s), t))
print('\n'.join(out))