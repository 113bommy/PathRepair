n = int(input())
st = set()
for i in range(n):
    s = input()
    s = s.replace("u", "oo")
    for j in range(30, 1, -1):
        t = str('k'*j+'h')
        s = s.replace(t, 'h')
    st.add(s)
print(len(st))
