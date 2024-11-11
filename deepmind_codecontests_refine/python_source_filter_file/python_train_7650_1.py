def SieveOfEratosthenes(n,ans): 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
      
    for p in range(2, n): 
        if prime[p]: 
            ans.append(p)
  
if __name__=='__main__': 
    n = int(input())
    prime=[]
    ans=[]
    SieveOfEratosthenes(n,prime) 
    for i in prime:
        k=1
        pow=i
        while(pow<=n):
            ans.append(str(pow))
            k+=1
            pow=i**k
    print(len(ans))
    print(" ".join(ans))
    