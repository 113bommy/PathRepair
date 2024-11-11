s=input()
z=0
for i in range(0,len(s)):
    if s[i]=="a" or s[i]=="e" or s[i]=="i" or s[i]=="o" or s[i]=="u" or s[i]=="n":
        continue
    else:
        if i==(len(s)-1):
            if s[i]=="a" or s[i]=="e" or s[i]=="i" or s[i]=="o" or s[i]=="u" or s[i]!="n":
                continue
            else:
                z=1
                break
        else:
            if s[i+1]!="a" and s[i+1]!="e" and s[i+1]!="i" and s[i+1]!="o" and s[i+1]!="u":
                z=1
                break
            else:
                continue
if z==1:
    print("NO")
else:
    print("YES")
