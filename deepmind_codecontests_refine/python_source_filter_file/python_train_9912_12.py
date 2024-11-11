t= int(input())

for _ in range(t):
    
    n,s = list(map(int,input().split()))
    
    a = list(map(int,input().split()))
    
    m = [-1,-1] 
    res = 0
    flag=0
    i=0
    while(i<n):
        # print("res",res," a[i] ",a[i])
        if m[0] < a[i]:
            m[0] = a[i]
            m[1] = i
        
        if res>s and a[i]>s:
            print(0)
            flag=1
            break
        
            
        elif res>s and a[i]<s:
            flag=1
            print(m[1]+1)
            break
            
        res+=a[i]
        i+=1
    if(flag==0 and res>s):
        print(i)
        
    elif flag==0:
        print(0)