


if __name__=="__main__":
    n=int(input())
    s=str(input())

    res=""

    for i in range(n):
        if s[i]=='0' or s[i]=='1': continue

        if s[i]=='4': res+="322"
        elif s[i]=='6': res+="53"
        elif s[i]=='8': res+="7222"
        elif s[i]=='9': res+="7332"
        else: res+=s[i]
    res=''.join(sorted(res,reverse=True))
    
    print(res)
