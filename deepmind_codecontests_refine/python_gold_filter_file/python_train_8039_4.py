def checkpal(s , i ):
    k1 = 0 
    k2 = i 
    while( k1 <= k2):
        if (s[k1] != s[k2]): 
            return False 
        else : 
            k1+=1 
            k2-=1 
    return True 
        
def lps(s): 
    l = len(s)
    ans = ""
    for i in range(0,l): 
        if ( checkpal(s ,i)):
            ans = s[0:i+1]
    return ans 
for _ in range(int(input())):
            s = input()
            l = len(s)
            if (l ==1):
                print(s)
            else: 
                i = 0 
                j = l-1 
                begin = ''
                while(i < j ): 
                    if (s[i] != s[j]): 
                        break 
                    else : 
                        begin += s[i] 
                        i+=1 
                        j-=1 
                rs = s[::-1]
                mids = s[i:j+1]
                #print(begin , mids)
                #print("mids : " , mids , "rmids : " , mids[::-1])
                k = lps(mids)
                rmids = lps(mids[::-1])
                mids = k 
                
                #print("mids : " , mids , "rmids : " ,rmids)
                print(begin , end= "")
                if (len(mids)  > len(rmids)): 
                    print(mids , end= "")
                else : print(rmids , end= "")
                print(begin[::-1])