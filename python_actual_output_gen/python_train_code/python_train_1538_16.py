import sys
s=input()
for x in range(len(s)):
    for y in range(x,len(s)):
        if s[:x]+s[y:]=='CODEFORCES':
            print("YES")
            sys.exit(0)
print("NO")