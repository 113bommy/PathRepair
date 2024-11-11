
def s_4(s,n) : 

    if len(s) != len(T) : 
        print("String must be the same length") 
    
    else : 
        # iterate loop in the reverse order 
        for i in range(n - 1,-1,-1) :
             
             if s[i] != 'z' :
                 k = ord(s[i])
                 s[i] = chr(k+1)  

                 return ''.join(s) 
             s[i] = 'a'
            

if __name__== "__main__" :
    str_1 = input()
    T = input() 
    S = list(str_1)
    n = len(S) 
    res = s_4(S,n) 

# approach if two srings are the same return no such string else s 

    if res != T : 
        print(res) 
    else : 
        print("No such string") 





            
                




