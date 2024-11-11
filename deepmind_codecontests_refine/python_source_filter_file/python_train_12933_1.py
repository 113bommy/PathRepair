import sys
input = sys.stdin.readline
input_list = lambda: list(map(int, input().split()))

def factorize(n):
    a = []
    i = 1
    while i*i<=n:
        if n % i == 0:
            a.append(i)
            if i*i != n:
                a.append(n//i)
            
        i += 1
    return a


def main():
    t = int(input())
    while t>0:
        t -= 1
        n = int(input())
        p = input_list()
        c = input_list()
        ans = len(p)
        used = [False]*(len(p) + 1)
        length = len(p)
        for i in range(length):
            if used[i]:continue
            used[i] = True
            j = p[i] - 1
            temp = [i]
            while j!=i:
                j = p[j] - 1
                used[j] = True
                temp.append(j)
            t_len = len(temp)
            factors = factorize(t_len)
            ans = min(ans, t_len)
            for k in factors:
                for l in range(k):
                    index = (l + k)%t_len
                    while(index != l and c[temp[(index - k + t_len)%t_len]] == c[temp[index]]):
                        index = (index + k)%t_len
                    if (index == l):
                        ans = min(ans, k)
        print(ans)                
                    

                  

    



            
    
       
    #stop = timeit.default_timer()
    #print(stop - start)
        
def exp(a, n):
    if n==0: return 1
    result = a
    residue = 1
    while n>1:
        if n%2==1: residue  = residue * result % MOD
        result = result * result % MOD
    return result * residue % MOD



# call to the main function
main()