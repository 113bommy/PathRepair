s=list(input())
flag=0
for i in range(len(s)):
    if s[i]=="a":
        if flag==1:
            break
    else:
        flag=1
        s[i]=chr(ord(s[i])-1)
if flag==0:
    s[-1]="Z"
print("".join(s))

    