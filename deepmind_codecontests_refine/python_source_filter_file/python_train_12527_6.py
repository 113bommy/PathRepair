q=[]

def is_valid(s,n):
    first_dot=0
    last_dot=n-1
    for i in range(n):
        if s[i]=='.' :
            break
        first_dot+=1

    for i in range(n-1,-1,-1):
        if s[i]=='.' :
            break
        last_dot-=1
    if first_dot > last_dot :
        return(False)
    if first_dot>8 or first_dot==0 or (n-1)-last_dot==0 or (n-1)-last_dot>8 :
        return(False)
    
    cnt=0
    for i in range(first_dot+1,last_dot+1):
        if s[i]=='.' :
            if cnt>11 or cnt<=1 :
                return(False)
            q.append(cnt)
            cnt=0
            continue
        cnt+=1
    
    return(True)

######################################
s=input()
n=len(s)
if not is_valid(s,n):
    print("NO")
    exit()
print('YES')
ans=''
answer=[]
for j in range(n):
    if s[j]=='.' :
        break
    ans+=s[j]

for i in q:
    if i>=4 :
        for l in range(4):
            ans+=s[j]
            j+=1
        answer.append(ans)
        ans=''
    else:
        for l in range(2):
            ans+=s[j]
            j+=1
        answer.append(ans)
        ans=''
    while s[j]!='.' :
        ans+=s[j]
        j+=1
while j<n :
    ans+=s[j]
    j+=1
answer.append(ans)
print('\n'.join(answer))
