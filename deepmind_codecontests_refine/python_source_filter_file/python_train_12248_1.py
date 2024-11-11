N, A, B = map(int, input().split())

for i in range(N+1):
    if (N-i*A)%B==0:
        ans = []
        
        for j in range(i):
            l = []
            
            for k in range(1, A+1):
                l.append(j*A+k)
                
            ans += l[1:]+[l[0]]
        
        for j in range((N-i*A)//B):
            l = []
            
            for k in range(1, B+1):
                l.append(i*A+j*B+k)
            
            ans += l[1:]+[l[0]]
        
        print(*ans)
        break
else:
    print(-1)