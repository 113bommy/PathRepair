alf = 'abcdefghijklmnopqrstuvwxyz'
st = input()
st = ' '.join(st)
st = st.split()
if len(st) == 1:
    print(st)
else:
    for i in range(1, len(st) - 1):
        if st[i] == st[i - 1]:
            for j in alf:
                if j != st[i - 1] and j != st[i + 1]:
                    st[i] = j
                    break
    if st[-1] == st[-2]:
        for j in alf:
            if j != st[-2]:
                st[-1] = j
                break
    for i in st:
        print(i, end = '')
