def palindrome_three (n):
    if n == 1:
        return "a"
    elif n == 2:
        return "ab"
    else:
        times = n//2
        ans = ""
        for x in range(1,times+1):
            if x%2 == 0:
                ans += "ab"
            else:
                ans += "ba"
        if n%2 != 0:
            ans += ans[-1]
        return ans


print (palindrome_three(int(input())))

        
                
                
                
     

     


          
          
          
     
