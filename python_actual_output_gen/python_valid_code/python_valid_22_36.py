n=int(input())
s=list(map(int,input().split()))
ch=0
bi=0
ba=0
c=0
for i in s:
    try:
        ch=ch+int(s[c])
        c+=1
    except:
        break
    try:
        bi=bi+int(s[c])
        c+=1
    except:
        break
    try:
        ba=ba+int(s[c])
        c+=1
    except:
        break
if bi<ch>ba:
    print("ch")
if ch<bi>ba:
    print("bi")
if ch<ba>bi:
    print("ba")