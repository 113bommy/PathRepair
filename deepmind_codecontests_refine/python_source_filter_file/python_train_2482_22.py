s = str(input())
t = str(input())
ss = []
for i in range(len(s)-len(t)+1):
    for j in range(len(t)):
        if s[i+j] not in ("?",t[j]):
            break
    else:
        s = s[:i]+t+s[i+len(t):]
        ss.append(s.replace("?","a"))
if ss:
    print(min(ss))
else:
    print("UNRESTORABLE")
