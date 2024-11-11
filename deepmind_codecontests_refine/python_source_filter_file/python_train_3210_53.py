a,b,k=map(int,input().split())

st=a
while st<=a+k-1 :
    print(st)
    st+=1
st=max(st,b-k+1)
while st<=b :
    print(st)
    st+=1
