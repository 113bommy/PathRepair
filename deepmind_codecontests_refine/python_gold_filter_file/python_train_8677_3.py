'''input
3
4 5 6
'''
def SieveOfEratosthenes(n): 
      
    # Create a boolean array "prime[0..n]" and initialize 
    #  all entries it as true. A value in prime[i] will 
    # finally be false if i is Not a prime, else true. 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
          
        # If prime[p] is not changed, then it is a prime 
        if (prime[p] == True): 
              
            # Update all multiples of p 
            for i in range(p * 2, n+1, p): 
                prime[i] = False
        p += 1


    arr = set()
    for i in range(2, n):
        if prime[i]:
            arr.add(i**2)


    return arr 


def main():
    n = int(input())
    valid = SieveOfEratosthenes(int(10e5))
    ans = map(int, input().split())
    for i in ans:
        if i in valid:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()
