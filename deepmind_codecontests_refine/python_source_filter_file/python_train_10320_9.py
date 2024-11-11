input=__import__('sys').stdin.readline
from collections import deque as dq
lis=[]
lis = dq(lis)
mat=[]
n = int(input())
aa=[[] for i in range(n+1)]
for i in range(n):
    a,b = map(int,input().split())
    mat.append([a,b])
    aa[a].append(b)
    aa[b].append(a)
st=[]
lis.append(1)
lis.append(aa[1][1])
lis.appendleft(aa[1][0])
st.append(aa[1][1])
st.append(aa[1][0])
dd=0
while len(st)!=0:
    dd+=1
    if dd==n:
        break
    a = st[0]
    st.pop(0)
    b,c = aa[a]
    if a==lis[0]:
        if b==lis[1]:
            lis.appendleft(c)
            st.append(c)
        else:
            lis.appendleft(b)
            st.append(b)
    else:
        if b==lis[-1]:
            lis.append(c)
            st.append(c)
        else:
            lis.append(b)
            st.append(b)
if sorted([lis[1],lis[2]])!=sorted(mat[lis[0]-1]):
    print(*list(lis)[:-2][::-1]) 
else:
    print(*list(lis)[:-2])               


    
    


