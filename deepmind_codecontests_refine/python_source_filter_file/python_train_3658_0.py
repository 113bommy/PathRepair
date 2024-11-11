for _ in range(int(input())):
    n = int(input())
    b = bin(n)[2:]
    a = len(b)
    b = list(b)
    ans = ""
    for i in b:
        if(i=='1'):
            ans+='0'
        else:
            ans+='1'
    if(a!=b.count("1")):
        bn = int(ans,2)
        print(bn^n)
    else:
        fans =0 
        for i in range(1,int(n**0.5)+1):
            if(n%i==0):
                fans = max(fans,max(i,n//i))
        if(fans == n):
            print(1)
        else:
            print(fans)
        
            
    