def arePermutation(str1, str2): 
      
    # Get lenghts of both strings 

    n1 = len(str1) 
    n2 = len(str2) 
  
    # If length of both strings is not same, 
    # then they cannot be Permutation 
    if (n1 != n2): 
        return False
    
    # Sort both strings 
    a = sorted(str1) 
     
    b = sorted(str2) 
    
    # Compare sorted strings 
    for i in range(0, n1): 
        if (a[i] != b[i]): 
            return False
  
    return True

def solve(s,s1):
    if(len(s1)<len(s)):
        print("NO")
        return
    for j in range(len(s1)-len(s)+1):
        
        if(arePermutation(s1[j:j+len(s)],s)==True):
            
            print("YES")
            return
    print("N0")
t=int(input())
for i in range(t):
    s=input()
    s1=input()
    solve(s,s1)
                
            
        