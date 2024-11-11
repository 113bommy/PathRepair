n = int(input())
s = 0

for i in range(n):
    a = list(map(int, input().split()))
    
    if n == 1 :
        s = a[0]
        
    elif n == 2 or n == 3:
        s += sum(a)
        
    else:
        
        if n % 2 == 0:
            s += a[i] + a[-i-1]
            
        else:
            
            if i == int(n/2)+1:
                s += sum(a)
                
            else:
                s += a[i] + a[-i-1] + a[int(n/2)+1]
print(s)