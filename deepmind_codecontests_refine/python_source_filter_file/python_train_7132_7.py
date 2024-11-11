s=str(input()); a=[]; v=0; k=0
map={")":"(","]":"[","}":"{",">":"<"}
for _ in range(len(s)):
    if s[_]=="<" or s[_]=="(" or s[_]=="{" or s[_]=="[":
        a.append(s[_])
    else:
        if len(a)==0:
            print("Impossible")
            k=1
            break
        elif a[-1]==map[s[_]]:
            a.pop(-1)
        else:
            a.pop(-1)
            v+=1
if k==0 and len(a)==0:
    print(v)
else:
    print("Impossible")