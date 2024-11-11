class Matrix():
    def __init__(self,ar):
        self.ar = ar

    def __mul__(self,other):
        n = len(other.ar)
        m = len(self.ar)
        p = len(other[0])
        ans = [[0]*p for i in range(m)]
        for i in range(m):
            for j in range(p):
                for k in range(n):
                    ans[i][j] += self[i][k] * other[k][j]
        return Matrix(ans)

    def __mod__(self,other):
        m = len(self[0])
        for i in range(len(self.ar)):
            for j in range(m):
                self[i][j] %= other
        return self
    
    def __getitem__(self, key):
        return self.ar[key]

mod = 10**9 + 9
def power(number, n):
    res = number
    while(n):
        if n & 1:
            res *= number
            res %= mod
            n -= 1
        
        number *= number
        number %= mod
        n >>= 1
    
    return res

n,m,k = map(int,input().split())

wrong = n - m
if wrong * k > n:
    print(m)
else:
    n -= wrong * k
    num = n // k
    m1 = Matrix([[0,k,k]])
    m2 = Matrix([[2,0,0],[1,1,0],[0,1,1]])
    if num == 0:
        print(m)
    elif num == 1:
        print((m + k) % mod)
    else:
        print((m + (m1 * power(m2,num - 1))[0][0]) % mod)
    


    #[k,i,1][[2,0,0]
    #        [1,1,0]
    #        [0,1,1]]
    #[k,k][[2,0]
    #       [1,1]]
    #[0,k,k]
    #[k,2k,k]
    #[4k,3k,k]
    #[11k,4k,k]
    #[26k,5k,k]
    #[57k,6k,k]
            
    #k 2*k+2k   8k + 3k  22k + 4k    52 k + 5k   104k+6k    
    #k 2k        3k         4k       5k          6k     
    
