n, st = int(input()), input()
r, l = st.count('R'), st.count('L')
r1, l1 = st.find('R'), st.find('L')
s, t = 0, 0
if (r == 0):
    print(l1+1,l1)
elif(l==0):
    print(r1+1,r+r1+1)
else:
    print(r1+1,l1)

