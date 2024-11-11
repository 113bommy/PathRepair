s1=input();s2=input();r=0;t1,t2="",""
if len(s1) == len(s2):
    for i in range(len(s1)):
        if r>2:
            print('NO')
            exit(0)
        if s1[i]!=s2[i]:
            r+=1
            t1+=s1[i]
            t2+=s2[i]
    if "".join(sorted(list(t1))) == "".join(sorted(list(t2))):
        print('YES')
    else:
        print("NO")
else:
    print('NO')