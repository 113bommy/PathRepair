def main():
    t = int(input())
    
    for i in range(t):
        n, k = map(int, input().split())
        
        ans = 0
        
        while n > 0:
            if n % k == 0:
                ans += 1
                n //= k
                
            else:
                x = n % k
                ans += x
                n -= x
        
        print(ans)
    
    
main()