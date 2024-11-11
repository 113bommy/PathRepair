s = input()
s1 = ""
cnt = 0
pos = 0
st = set()
for i in range(len(s)):
    if s[i] not in ['a', 'o', 'u', 'i', 'e', 'y']:
        cnt += 1
        st.add(s[i])
        #print(i, s[pos:i], cnt, st)
        if cnt >= 3 and len(st) > 1:
            s1 += s[pos:i] + ' ' 
            pos = i
            cnt = 1
            st = set(s[i])
    else:
        cnt = 0
        st = set()
s1 += s[pos:]
print(s1)    