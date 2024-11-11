ans=""
old=""
for c in input():
    if c==".":
        if old=="":
            ans+="0"
        else:
            ans+="1"
            old="-"
    else:
        if old=="-":
            ans+="2"
            old=""
        else:
            old="-"
print(ans)
        
