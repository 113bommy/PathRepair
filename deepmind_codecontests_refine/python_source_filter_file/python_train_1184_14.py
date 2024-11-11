def bs(n, k, lo, hi):
    
    while lo <= hi: 
        mid = (hi + lo)//2
        # print(lo, hi, mid)
        # print('start')
        # ks = range(mid, k+1)
        # print('end')
        # print('start')
        # summ = (mid + k) * ((k - mid +1)/2) - (k-2)
        # summ = (-mid * (mid -1) + k * (k + 1))/2 - (k-2)
        summ = ((k * (k + 1))//2 - 1) - (((mid-1) * (mid))//2 -1) - (k-2)
        # kk = k
        # summ = 0
        # while kk > 0:
        #     summ += summ
        #     kk -=1
        # summ = summ - (k-2)
        # summ = sum(ks) - (len(ks) - 1)
        # print('end')
        # print(list(range(mid, k+1)))
        # print(summ, n)
        # print(mid, k, (summ), 'mid')
        if summ == n: 
            # print('done')
            return k - mid + 1
            # print(f'result: {k - mid + 1}')
            # break
        if summ > n: 
            # print('hi')
            lo = mid + 1
            print(lo, hi, (hi + lo)//2)
            
        elif summ < n:
            hi = mid - 1
            # print((hi + lo)//2 , 'yarab', lo, hi)
            # print('lala')
            # print(summ)
    # print(lo, 'i am the mid')
    # if n - summ == 1:
    #     print('there') 
    #     return -1
    # summ = ((k * (k + 1))//2 - 1) - ((((mid+1)-1) * ((mid+1)))//2 -1) - (k-2)
    # print(summ, 'yalla')
    # print(mid, 'lol')
    # print(k - mid)
    # print('yo')
    if summ > n: 
       mid += 1
    return k - mid + 1
    # print(f'result: {k - mid + 2}')



def solve():
    n, k = map(int, input().split())
    # n, k = 499999999500000000, 1000000000
    # n, k = 8, 4
    if n == 1: return 0
    elif (k * (k + 1)//2) - (k-2) <= n: 
        # print('here')
        return -1
    elif k >= n: return 1
    else: 
        return bs(n, k, 2, k)

print(solve())