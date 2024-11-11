def search(array, i, j, l):

    if i > j or array[i] - array[0] > l:
        return -1
    mid = (i+j)//2
    if array[mid] - array[0] > l:
        return search(array, i, mid-1, l)
    else:
        return max(mid, search(array, mid+1, j, l))


if __name__ == '__main__':
    n, k, l = input().split()
    n = int(n)
    k = int(k)
    l = int(l)
    a = input().split()
    a = [int(x) for x in a]
    a.sort()
    ans = 0
    if k == 1:
       if a[n*k-1] - a[0] <= l:
           i = 0
           while i < n*k:
               ans += a[i]
               i += 1
       else:
           ans = 0
    else:
        ind = search(a,0, n*k-1, l)
        if ind + 1 < n: ans = 0
        else:
            count = n*k - ind - 1
            i = 0
            while i < count:
                ans += a[ind - i]
                i+=1
            i = 0
            while i < n - count:
                ans += a[i*k]
                i += 1
    print(ans)

