st1=input()
st2=input()
st3=''
n=len(st1)
for i in range(n):
    if st1[i]=='1':
        if st2[i]=='1':
            st3=st3+'0'
        else:
            st3=st3+'1'
    else:
        st3=st3+st2[i]
print(int(st3))
