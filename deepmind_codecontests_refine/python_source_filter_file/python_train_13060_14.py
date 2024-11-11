import math
N = 10**6 + 1
prime = [True for i in range(N)]
prime [0],prime[1] = False, False

def SOE():
    p = 2
    while p*p<=N:
        if prime[p]==True:
            for p1 in range(p+p, N, p):
                prime[p1] = False
        p+=1
SOE()  
n = int(input())
if n%2==0:
    print(n//2,n//2)
else:
    for i in range(n//2):
        if prime[i]==False and prime[n-i]==False:
            print(i,n-i)
            break