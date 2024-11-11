def f(s):
    i=0
    n=len(s)
    j = int(n)-1
    S = {'A','H','I','M','O','o','T','U','V','v','W','w','X','x','Y'}
    while(i<=j):
        if((s[i]=='b' and s[j]=='d') or (s[i]=='d' and s[j]=='b')):
            i+=1
            j-=1
            continue
        if((s[i]=='p' and s[j]=='q') or (s[i]=='q' and s[j]=='p')):
            i+=1
            j-=1
            continue
        if(s[i]!=s[j] or (s[i] not in S) or (s[j] not in S)):
            return False
        i+=1
        j-=1
    return True
s=input()
if(f(s)):print('TAK')
else:print('NIE')
    