t = int(input())
def LongestPalindromicPrefix(Str): 
  
    # Create temporary string 
    temp = Str + "?"
  
    # Reverse the string Str 
    Str = Str[::-1] 
  
    # Append string Str to temp 
    temp = temp + Str
  
    # Find the length of string temp 
    n = len(temp) 
  
    # lps[] array for string temp 
    lps = [0] * n 
  
    # Iterate the string temp 
    for i in range(1, n): 
  
        # Length of longest prefix  
        # till less than i 
        Len = lps[i - 1] 
  
        # Calculate length for i+1 
        while (Len > 0 and temp[Len] != temp[i]): 
            Len = lps[Len - 1] 
  
        # If character at currrent index 
        # Len are same then increment 
        # length by 1 
        if (temp[i] == temp[Len]): 
            Len += 1
  
        # Update the length at current 
        # index to Len 
        lps[i] = Len
  
    # Print the palindromic string 
    # of max_len 
    return temp[0 : lps[n - 1]]
for i in range(t):
    s = input()
    A = [ch for ch in s]
    pre = []
    suf = []
    i = 0
    j = len(A)-1
    while (i<j and A[i]==A[j]):
        pre.append(A[i])
        suf.append(A[j])
        i+=1 
        j-=1 
    
    mid = s[i:j+1]
    ans = ''
    if len(LongestPalindromicPrefix(mid))>len(LongestPalindromicPrefix(mid[::-1])):
        ans = LongestPalindromicPrefix(mid)
    else:
        ans = LongestPalindromicPrefix(mid[::-1])
    ans = "".join(pre) + ans + "".join(suf[::-1])
    print(ans)