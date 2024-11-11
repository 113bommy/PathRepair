from math import factorial

def short_perm_to_num(perm, n): # O(n**2), but n <= 70
    result = 0
    is_used = {}
    for i in range(n):
        for j in range(perm[i]):
            if not (j in is_used):
                result += factorial(n-1-i)
        is_used[perm[i]] = True
    return result

def perm_to_num(perm, n):
    max_len = 15
    if n <= max_len:
        return short_perm_to_num(perm, n)
    else:
        last_part = [x - (n-max_len) for x in perm[n-max_len:]]
        return short_perm_to_num(last_part, max_len)

def short_num_to_perm(num, n):
    is_used = {}
    perm = []
    for i in range(n):
        deg = num // factorial(n-1-i)
        num %= factorial(n-1-i)
        j = 0
        while j in is_used:
            j += 1
        # now j is 1st unused item
        deg_of_j = 0
        while (deg_of_j < deg) or (j in is_used):
            if not (j in is_used):
                deg_of_j += 1
            j += 1
        perm.append(j)
        is_used[j] = True
    return perm

def num_to_perm(num, n): # RETURNS ONLY LAST 15 SYMBOLS
    max_len = 15
    if n <= max_len:
        return short_num_to_perm(num, n)
    else:
        last_part_low = short_num_to_perm(num, max_len)
        last_part = [x + (n-max_len) for x in last_part_low]
        return last_part


[n, q] = [int(x) for x in input().split()]
full_perm = [i for i in range(0, n)] # full permutation as an array, but don't forget to add 1 when printing
num_of_perm = 0

# 70! is just above 10**100, so elements before the last 70 are still 1, 2, 3, ... n-7


for quarry_num in range(q):
    quarry = [int(x) for x in input().split()]
    if quarry[0] == 1:
        perm = num_to_perm(num_of_perm, n)
        l = quarry[1]
        r = quarry[2]
        if n <= 15:
            print(sum(perm[l-1:r]) + r-l+1)
        else: # n-15, n-14, ... n-1 are in the perm; we must compute sum(perm[l-1:r])
            if l-1 >= n-15:
                print(sum(perm[l-1-n+15:r-n+15]) + r-l+1)
            else: # l-1 < n-15
                if r < n-15:
                    s = ((l-1) + r-1) * (r-1 - l+1 + 1) // 2
                    print(s + r-l+1)
                else:
                    s = ((l-1) + n-16) * (n-16 - l + 2) // 2
                    rest = sum(perm[:r-n+15])
                    print(s + rest + r-l+1)
    if quarry[0] == 2:
        num_of_perm += quarry[1]

