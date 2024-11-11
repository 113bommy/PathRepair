s=int(input())
st=set()
st.add(s)
for i in range(2,10**6):
  t=s//2 if s%2==0 else 3*s+1
  if t in st:
    print(i)
    break
  st.add(t)
