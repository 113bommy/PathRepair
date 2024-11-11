string=input()
n=len(string)
count1=[]
long=0
for s_i in range(n):
    for end_i in range(s_i+1,n):
        sub=string[s_i:end_i+1]
        if sub not in count1:
            count1.append(sub)
        else:
            if len(sub)>long:
                long=len(sub)
                
                    

print(long)            
        
               
