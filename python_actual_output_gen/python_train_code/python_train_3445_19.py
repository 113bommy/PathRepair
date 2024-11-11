a,b=map(int,input().split(':'))

b+=1
for i in range(a,24) :
    e=str(i)
    if len(e)==1 :
        e="0"+e
    
    for j in range(60) :
        
        e1=str(j)
        
        if len(e1)==1 :
            e1="0"+e1
        
        if e==e1[::-1]  :
            if int(e)>a or int(e1)>b :
                print(e+":"+e1)
                exit()
            
print("00:00")
        
