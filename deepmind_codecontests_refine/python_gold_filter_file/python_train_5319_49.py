def solve(n):
    n = n - n/s[0];
    for i in range(1, len(s)):
        n = n - n/s1[i]
        n = n - n/s[i]
        if n < m :
            return False
        
    n = n - n/s1[0]
    return n>=m

n = int(input())
m = int(input())

s =  list( int(x) for x in  input().split( ))
s1 = list(int(x)for x  in input().split( ))


low = 1
high = (10**9) + 5



while(high - low > 0.000001):
    mid = (high+low)/2
    if solve(mid + m ):
        high= mid;
    else:
        low = mid;
        
        
if(solve(low + m )):
    print(low);
elif(solve(high+ m)):
    print(high)
    
else:
    print(-1)


    
