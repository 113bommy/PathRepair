l = int(input())
st = input()
se = ["jolteon","flareon","umbreon","leafeon","glaceon","sylveon"]
se = [c[:4] for c in se if len(c)==7]

sus = ""

if l==6:
    print("espeon")
elif l==8:
    print("vaporeon")
else:
    st = st[:4]

    for suspect in se:
        match = True

        for i in range(0, len(st)):
            ch = st[i]
            if ch==".":
                continue
            else:
                if suspect[i]!=ch:
                    match = False
                    break
        if match:
            sus = suspect
            break

    print(sus+"eon")



