s = input()
for i in range(26):
    for j in range(len(s)+1):
        s1 = s[:j]+chr(ord('a')+i)+s[j:]
        if s1[::-1] == s1:
            print (s1)
            exit(0)
print ('NA')