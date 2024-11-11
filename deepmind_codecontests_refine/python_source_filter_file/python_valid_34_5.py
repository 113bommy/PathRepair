for test in range(int(input())):
    def solve():
        n , k = map(int,input().split())
        arr = list(map(int,input().split()))
        ar = arr[-k:]
        k1 = len(ar)
        ans = -9999999999999
        add = n - k1 +1
        for i in range(k1):
            for j in range(i+1,k1):
                ans = max ( ans ,  (add+i)* (add+j) - k * (ar[i] | ar[j]) )
        return ans
    print(solve())