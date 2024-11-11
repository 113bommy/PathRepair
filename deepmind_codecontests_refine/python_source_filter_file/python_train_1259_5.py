s = "abcdefghijklmnopqrstuvwxyz"
def check(x,y):
    try:
        if s[s.index(x)-1]==s[s.index(y)+1] or s[s.index(x)-1]==s[s.index(y)-1] or s[s.index(x)+1]==s[s.index(y)-1] or s[s.index(x)+1]==s[s.index(y)+1]:
            return 1
        else:
            return 0
    except:
        if (x=='a' and y=='z') or (x=='z' and y=='a'):
            return 0
        elif x=='z':
            if s[s.index(x)-1]==s[s.index(y)+1] or s[s.index(x)-1]==s[s.index(y)-1] or 'a'==s[s.index(y)-1] or 'a'==s[s.index(y)+1]:
                return 1
            else:
                return 0
        elif y=='z':
            if s[s.index(x)-1]=='a' or s[s.index(x)-1]==s[s.index(y)-1] or s[s.index(x)+1]==s[s.index(y)-1] or s[s.index(x)+1]=='a':
                return 1
            else:
                return 0
    
q = int(input())
for i in range(q):
    n = (int(input())) // 2
    s1 = input()
    r = 1
    f = s1[:n]
    m = s1[n:][::-1]
    for j in range(n):
        if f[j]!=m[j]:
            if not check(f[j],m[j]):
                r = 0
                print("NO")
                break
    if r:
        print("YES")
        
