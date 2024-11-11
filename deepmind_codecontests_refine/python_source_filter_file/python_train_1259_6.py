t = int(input())

def pal(n,s):
    x = 0
    for i in range (int(n/2)):
        if (ord(s[i])+1)  == (ord(s[n-1-i])+1) or (ord(s[i])-1) == (ord(s[n-1-i])-1) or (ord(s[i])-1)== (ord(s[n-1-i])+1) or (ord(s[i])+1) == (ord(s[n-1-i])-1):
            x += 1
    if x == int(n/2):
        print("yes")
    else:
        print("no")
for j in range (t):
    n = int(input())
    s = input()
    pal(n,s)