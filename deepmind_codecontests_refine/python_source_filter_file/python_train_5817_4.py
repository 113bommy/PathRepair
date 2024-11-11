string=input()
ans=""
for x in string:
    if x!="b":
        ans+=x
    else:
        ans=ans[:-1]
print(ans)