t = input()
t = '_' +input()+'_'
res = ''
for i in range(1,len(t)):
    if (not((t[i] == '_')and(t[i-1] == '_'))and((t[i] != '(')and(t[i] != ')'))):
        res+=t[i]
    if ((t[i] == '(')or(t[i] == ')')):
        if (t[i-1] != '_'):
            res += '_'
        res += t[i]
        if (i != len(t)-1):
            if(t[i+1] != '_'):
                res += '_'
s = list(res.split('_'))
sk = False
n = 0
d = 0
for i in range(0, len(s)):
    if ((s[i] != '(')and(s[i] != ')')and(sk)and(s[i] != '')):
        n += 1
    if ((s[i] != '(')and(s[i] != ')')and(not(sk))and(len(s[i]) > d)):
        d = len(s[i])
    if ((s[i] == '(')or(s[i] == ')')):
        sk = not(sk)
print(d,n)
