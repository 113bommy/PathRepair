s=list(input())
st=[]
a=[0]*len(s)
for i in range(len(s)):
    if s[i]==']':
        if len(st)>0 and st[-1][0]=='[':
            a[st[-1][1]]=i
            st.pop()
        else:
            st=[]
    elif s[i]==')':
        if len(st)>0 and st[-1][0]=='(':
            a[st[-1][1]]=i
            st.pop()
        else:
            st=[]
    else:
        st.append([s[i],i])

mans=0
ml=0
mr=0



def kkk(s,l,r):
    ans=0
    for i in range(l,r+1):
        if s[i]=='[':
            ans+=1
    return ans
        
i=0
while i<len(s):
    while i<len(s) and a[i]==0: i+=1
    if i<len(s):
        l=i
        r=a[i]
        while r+1<len(s) and a[r+1]>0: r=a[r+1]
        t=kkk(s,l,r)
        if t>mans:
            mans=t
            ml=l
            mr=r
        i=r+1

print(mans,ml,mr)
if mans>0:
    for i in range(ml,mr+1):
        print(s[i],end='')
