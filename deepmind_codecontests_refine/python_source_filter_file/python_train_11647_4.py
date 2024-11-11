import sys
s = input()
a = 'qwertyuiopasdfghjklzxcvbnm'
for i in a:
    for n in range(len(s)-1):
        if i+i == s[n:n+1]:
            print(n,n+1)
            sys.exit()
    for n in range(len(s)-2):
        if i == s[n] and i == s[n+1]:
            print(n,n+2)
            sys.exit()
print(-1,-1)
