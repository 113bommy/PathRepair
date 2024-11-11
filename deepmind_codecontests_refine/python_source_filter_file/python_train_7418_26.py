from collections import Counter
from collections import OrderedDict
#ordered dict in sorted order(reverse) with frequency count
def SOCountR(mylist):
    return OrderedDict(sorted(Counter(mylist).items(),reverse=True))

def SOCount(mylist):
    return OrderedDict(sorted(Counter(mylist).items()))

#frequency Count
def freq_count(mylist):
    return Counter(mylist)

def isPrime(n) : 
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True
    
t=int(input())
for _ in range(t):
    n=int(input())
    n=n-30
    if n < 0:
        print("NO")
    else:
        if n == 6 or n == 10 or n == 14:
            n-=1
            if n < 1:
                print("NO")
            else:
                print("YES")
                print("6 10 15",n)
        else:
            print("YES")
            print("6 10 14",n)