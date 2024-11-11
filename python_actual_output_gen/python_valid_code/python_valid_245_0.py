n = input().split()
n = int(n[0])
print(n)
se = []
s=''

for i in range(n):
    st=input()
    g = st.index('G')
    s = st.index('S')
    s-=g
    if s<=0:
        print(-1)
        quit()
    elif not s in se:
        se.append(s)
    print(se)
print(len(se))
