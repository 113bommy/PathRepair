s=input()
t=input()
s_len=(len(s))
t_len=(len(t))

for i in range(s_len-t_len,-1,-1):
    for j in range(t_len):
        if s[i+j]!=t[j] and s[i+j]!="?":
            break
    else:
        print((s[:i]+t+s[i+s_len:]).replace("?","a"))
        exit()

print("UNRESTORABLE")
