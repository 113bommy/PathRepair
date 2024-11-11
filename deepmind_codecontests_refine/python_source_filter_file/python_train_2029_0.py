s=input()
i=0
flag=0
while(i<len(s)):
    if s[i:i+2]=="AB":
        i+=2
        if "BA" in s[i:]:
            print("YES")
            flag=1
            break
        # else:
        #     print("NO")
        #     break
    elif s[i:i+2]=="BA":
        i+=2
        if "AB" in s[i+2:]:
            print("YES")
            flag=1
            break
        # else:
        #     print("NO")
        #     break
    i+=1
if flag==0:
    print("NO")
            
    