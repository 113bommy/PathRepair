x = int(input())
lst =[]
st  = ''
for i in range(x):
    lst.append(int(input()))

for i in lst:
    st = ''
    while len(st)<998244353 and i>=2:
        st = '1'+st
        i-=2

    st = list(st)
    for j in range(len(st)):
        if i>=5:
            st[j]='9'
            i-=5
            continue
        elif i>=1:
            st[j] = '7'
            i-=3
            continue
    print(''.join(st))
