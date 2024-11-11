n=int(input())
l=[int(x) for x in  input().split()]
st=[]
for i in l:
    d=i%2
    if len(st) and st[-1]==d:
        st.pop()
    else:
        st.append(d)
if len(st)<2:
    print("YES")
else:
    print("NO")