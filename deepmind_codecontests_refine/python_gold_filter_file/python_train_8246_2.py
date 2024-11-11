#for _ in range(int(input())):
import math    
n = int(input())
s = list(input())


for i in range(26):
    t = 122-i
    j = 0
    for k in range(n):
        for j in range(len(s)):
            if ord(s[j]) == t:
                if j>0 and ord(s[j-1]) == t-1:
                    s.pop(j)
                    break

                elif j<len(s)-1 and ord(s[j+1]) == t-1:
                    s.pop(j)
                    break
    #print(s)

#print(s)
print(n-len(s))
                





    

