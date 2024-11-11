s = input()
st = []
st.append(s[0])
turn = 0
for i in range(1, len(s)):
    if(len(st) != 0 and s[i] == st[-1]):
        st.pop()
        turn += 1
    else:
        st.append(s[i])

if (turn % 2 == 0):
	print("No")
else:
	print("Yes")