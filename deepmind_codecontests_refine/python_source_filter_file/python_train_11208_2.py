n=int(input())
st=input()
count=0
while 'xxx' in st:  
    st=st.replace('x','',1)
    count+=1
print(count)