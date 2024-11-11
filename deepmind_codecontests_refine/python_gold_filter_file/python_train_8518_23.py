#2017 code festival a
s=input()
if len(s)>9 or ("AA" in s)or ("KIH" not in s):
    print("NO")
else:
    new_s=""
    for i in range(len(s)):
        if s[i]!="A":
            new_s+=s[i]
    if new_s=="KIHBR":
        print("YES")
    else:
        print("NO")