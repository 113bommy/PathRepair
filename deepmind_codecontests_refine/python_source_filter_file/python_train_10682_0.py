n,k,t=map(int,input().split())
if k > t:
    print(t)
elif n > t > k:
    print(t)
else:
    print(n+k-t)
            
    
