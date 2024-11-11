n = int(input(""))
s = str(input(""))

c = 0
for i in range(0, n - 1):
    for f in range(i + 2, n + 1):
        if s[i:f].count('R') == s[i:f].count('L') and s[i:f].count('U') == s[i:f].count('D'): 
            c = c + 1
            r = 'S'
        else:
            r = ''
        #print (i, f, s[i:f], r)

print (c)