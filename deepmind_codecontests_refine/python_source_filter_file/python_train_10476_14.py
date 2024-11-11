n=input()

k=0
i=0
for i in range(len(n)) :
    if n[i]=='Q' :
        for i in range(i,len(n)):
            if n[i]=='A':
                for i in range(i,len(n)):
                    if n[i]=='Q' :
                        k+=1
            
    
