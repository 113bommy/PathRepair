q=int(input())

def solve(s,t):
    m=len(s)
    n=len(t)

    if m%2 != n%2:
        s=s[1:]
        m-=1

    if m<n:
        return False

    u=[]
    cnt=0
    for i in range(m):
        #print(s,t,u,cnt)
        if cnt==0:
            u.append(s[i])
            cnt+=1
        elif cnt==n:
            u.pop()
            cnt-=1
        elif u[cnt-1]==t[cnt-1]:
            u.append(s[i])
            cnt+=1
        elif t[cnt-1]!=u[cnt-1]:
            u.pop()
            cnt-=1
        #print(s,t,u,cnt)
    return ''.join(u)==t

for ind in range(q):
    s=input()
    t=input()
    print('Yes' if solve(s,t) else 'No')