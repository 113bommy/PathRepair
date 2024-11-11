for _ in range(int(input())):
    s = input()
    c = 1
    st = set()
    e = 0
    for i in range(len(s)):
        if i == 0:
            e = s[0]
            if len(s) == 1:
                st.add(e)
            continue
        if s[i] == e:
            c += 1
        else:
            if c % 2 == 1:
                st.add(e)
            c = 1
            e = s[i]
    if c % 2 == 1:
        st.add(s[len(s) - 1])
    k = ''.join(list(st))
    print(k)
