s=input()

flag=True
KIHBR="KIHBR"
s_new=s.replace("A", "")
if len(s_new)>5:
    flag=False
else:
    for i in range(5):
        if s_new[i]!=KIHBR[i]:
            flag=False
            break

if s.count("AA")>1 or s.count("KIH")!=1:
    flag=False

print("YES" if flag else "NO")
