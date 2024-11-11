import os
from io import BytesIO
#input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

def main():
    mod = 10**9 + 7
    n,b,k,x = map(int,input().split())
    x2 = x + 1
    ai = list(map(int,input().split()))
    ai2 = [0]*x2
    for i in range(n):
        ai2[ai[i] % x] += 1
    ai2[-1] = 1

    def power2(number, n, m):
        res = 1
        while(n):
            if n & 1:
                res *= number
                res %= m
            
            number *= number
            number %= m
            n >>= 1
        
        return res
    
    def mult(m1,m2):
        ans = [0] * x2

        for i in range(x):
            for j in range(x):
                temp = (i*power2(10,m2[-1],x)+j) % x
                ans[temp] += m1[i] * m2[j] 
                ans[temp] %= mod
        ans[-1] = (m1[-1] + m2[-1]) % x
        return ans
    
    def power(number, n):
        res = number
        while(n):
            if n & 1:
                res = mult(res,number)
            
            number = mult(number,number)
            n >>= 1
        
        return res

    
    ansm = power(ai2,b-1)
    print(ansm[k])
main()
