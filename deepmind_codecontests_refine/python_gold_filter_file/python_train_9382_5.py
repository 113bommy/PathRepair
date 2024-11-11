n=int(input())
a=list(map(int,input().split()))
st=[]
for i in a:
    if len(st)>0 and st[-1]==(i&1):
        st.pop()
    else:
        st.append(i&1)
if len(st)<=1:
    exit(print("YES"))
print("NO")