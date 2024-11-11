
t=int(input())
for _ in range(t):
    P=int(input())
    dic={}
    for i in range(2,P+1):
        rem=P%i
        brk=False
        # print(i,rem,dic)
        try:
            if dic[rem]:
                print(dic[rem],i)
                brk=True
        
        except KeyError:
            dic[rem]=i
        
        if brk:break
    
    