for _ in range(int(input())):
    n=int(input())
    s=input()
    s1="abacaba"
    if s1 in s:
        count = 0
        for i in range(len(s) - 6):
            if s[i] == "a" and s[i:i + 7] == s1:
                count += 1
        if count==1:
            for i in range(s.count("?")):
                s1=s.replace("?","z")
            print("Yes")
            print(s1)
        else:
            print("No")
    else:
        for i in range(len(s) - 6):
            if s[i] == "a" or s[i]== "?":
                x=0
                for j in range(i,i+7):
                    if not(s[j]==s1[x] or s[j]=="?"):
                        break
                    x+=1
                else:
                    s2=s[:i]+s1+s[i+7:]
                    s2=list(s2)
                    for i in range(len(s2)):
                        if s2[i]=="?":
                            s2[i]="z"
                    s2="".join(s2)
                    cnt=0
                    for i in range(len(s) - 6):
                        if s2[i] == "a" and s2[i:i + 7] == s1:
                            cnt += 1
                    if cnt==1:
                        print("Yes")
                        print("".join(s2))
                        break

        else:
            print("No")




