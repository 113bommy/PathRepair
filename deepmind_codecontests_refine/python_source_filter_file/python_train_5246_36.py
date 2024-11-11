n = int(input())
st = '.' + input()
tmp = 'L'
if st.count('R'):
    tmp = 'R'
s,t = st.find(tmp), st.rfind(tmp)
if tmp == 'L':
    s = t
    t = s-1
else:
    t += 1
print(s,t)
