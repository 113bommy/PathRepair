s = input()
for i in range(26):
    for j in range(len(s)+1):
        s1 = s[:i]+chr(ord('a')+i)+s[i:]
        if s1[::-1] == s1:
            print (s1)
            exit(0)
print ('NA')