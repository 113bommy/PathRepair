s=input()
p=input()
n=len(s)
ans=0
for i in range(0,n,2):
    if s[i:i+2]=='8<':
        if p[i:i+2]=='[]':
            ans+=1
        elif p[i:i+2]=='()':
            ans-=1
    if s[i:i+2]=='[]':
            if p[i:i+2]=='()':
                ans+=1
            elif p[i:i+2]=='8<':
                ans-=1
    if s[i:i+2]=='()':
            if p[i:i+2]=='8<':
                ans+=1
            elif p[i:i+2]=='[]':
                ans-=1
if ans<0:
    print('TEAM 2 WINS')
elif ans==0:
    print('TIE')
else:
    print('TEAM 1 WINS')