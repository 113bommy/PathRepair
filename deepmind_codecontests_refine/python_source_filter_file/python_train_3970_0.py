n=int(input())
s=[[] for i in range(n-1)]
st=[]
for i in range(2*n-2):
    t=input()
    if len(t)==n-1:
        st.append([t,i])
    else:
        s[len(t)].append([t,i])

if n==2:
    print('PS')
    exit()
for v in range(2):
    if v==0:
        top=st[0][0]
        bot=st[-1][0]
        m1=st[0][1]
        m2=st[-1][1]
    else:
        top=st[-1][0]
        bot=st[0][0]
        m1=st[-1][1]
        m2=st[0][1]
    ans=['' for i in range(2*n-2)]
    f2=0
    ans[m1]='P'
    ans[m2]='S'
    for i in range(1,n-1):
        f1=0
        for j in range(2):
            if j==0:
                val1=s[i][0][0]
                m1=s[i][0][1]
                val2=s[i][1][0]
                m2=s[i][1][1]
                if top[:i]==val1 and bot[n-i-1:]==val2:
                    ans[m1]='P'
                    ans[m2]='S'
                    f1=1
            else:
                if f1:
                    continue
                val1=s[i][1][0]
                m1=s[i][1][1]
                val2=s[i][0][0]
                m2=s[i][0][1]
                if top[:i]==val1 and bot[n-i-1:]==val2:
                    ans[m1]='S'
                    ans[m2]='P'
                else:
                    f2=1
    if f2==0:
        break
out=''.join(ans)
print(out)
