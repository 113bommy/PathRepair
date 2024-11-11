t = int(input())
while(t>0):
    n =int(input())
    s =input()
    k=[]
    arr=[]
    for i in range(0,n):
        s1= s[i:n+1]
        s2=s[0:i]
        if(n%2 != 0 and i%2== 0 ):
            s2 = s2[::-1]
        elif(n%2 == 0 and i%2!= 0 ):
            s2 = s2[::-1]
        
        
        k.append(s1+s2)
    for i in range(0,len(k)):
        arr.append(k[i])
    arr.sort()
    ans = -1
    
    for i in range(0,len(k)):
        if(k[i]==arr[0]):
            ans =i+1
            break
        
    print(arr[0])    
    print(ans)    
    t = t-1
    