R = lambda: list(map(int,input().split()))
s = input()
ok = True
ans = 0
st = []
opn = set("<[({")
inv = {'}':'{', ')':'(', '>':'<', ']':'['}
for i in s:
    if i in opn:
        st.append(i)
    else:
        if not st:
            ok = False
            break
        if inv[i]!=st[-1]: ans += 1
        st.pop()
if not ok or st: print("Impossible")
else: print(ans)