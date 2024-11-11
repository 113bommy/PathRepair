s=input()
t=input()
flag=1
for i in range(len(s)):
    if s[i]==t[len(t)-i-1]:
        continue
    else:
        print("NO")
        flag=0
        break
if flag==1:
    print("YES")