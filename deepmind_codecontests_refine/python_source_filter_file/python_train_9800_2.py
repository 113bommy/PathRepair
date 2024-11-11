#!/usr/bin/env python
# coding: utf-8

# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:


while True:
    if input()=='start':

        
        print(*['?',0,1],flush=True)
        
        result=input()
        
        if result=='x':
            print(*['!', 1],flush=True)
            continue
            
        
        
        i=0
        while True:
            print(*['?', 2**i, 2**(i+1)],flush=True)
            

            result=input()

            if result=='y':
                i+=1

            else:
                
                break

        j=i-1
        result=2**i
        

        while j>0:
            print(*['?', result, result+2**j],flush=True)
            

            read=input()

            if read=='y':
                
                result=result+2**(j)
                j=j-1
                

            else:
                
    
                j=j-1


                
            
        print(*['!', result+1],flush=True)
        
        
    else:
        break

