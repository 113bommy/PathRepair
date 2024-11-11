n=int(input())
a=list(map(int,input().split()))
d={}
for i in a:
    d[i]=d.get(i,0)+1
ans=[[0]*n for i in range(n)]
st=[]
for i in d.keys():
    st.append(i)
for i in range(n//2):
    for j in range(n//2):
        try:
            while len(st)>0 and d[st[-1]]==0:
                st.pop()
            while len(st)>0 and d[st[-1]]<4:
                st.pop()
            if ans[i][j]==0:
                ans[i][j]=st[-1]
                d[st[-1]]-=1
            if ans[n-i-1][j]==0:
                ans[n-i-1][j]=st[-1]
                d[st[-1]]-=1
            if ans[i][n-j-1]==0:
                ans[i][n-j-1]=st[-1]
                d[st[-1]]-=1
            if ans[n-i-1][n-j-1]==0:
                ans[n-i-1][n-j-1]=st[-1]
                d[st[-1]]-=1
        except:
            exit(print('NO',4))
st=list(d.keys())
#print(ans,d)
for i in range(n//2):
    try:
        while len(st)>0 and d[st[-1]]==0:
            st.pop()
        while len(st)>0 and d[st[-1]]<2:
            st.pop()
        if n%2:
            ans[i][n//2]=st[-1]
            ans[n-1-i][n//2]=st[-1]
            d[st[-1]]-=2
    except:
        exit(print('NO',3))
r=list(d.keys())
#print(d)
for i in range(n//2):
    try:
        while len(r)>0 and d[r[-1]]==0:
            r.pop()
        while len(r)>0 and d[r[-1]]<2:
            r.pop()
        if n%2:
            ans[n//2][i]=r[-1]
            ans[n//2][n-i-1]=r[-1]
            d[r[-1]]-=2
    except:
        exit(print('NO',5))
for i in d.keys():
    if d[i]!=0 and n%2:
        ans[n//2][n//2]=i
        break
#print(ans)
for i in range(n):
    for j in range(n):
        if ans[i][j]==0:
            exit(print('NO',1))
print('YES')
for i in range(n):
    print(*ans[i])