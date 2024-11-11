s="qwertyuiopasdfghjkl;zxcvbnm,./"
side=input()
a=input()
ans=''
for i in a:
    if side=='R':
        ans+=s[a.index(i)-1]
    else:
        ans+=s[a.index(i)+1]
print(ans)
