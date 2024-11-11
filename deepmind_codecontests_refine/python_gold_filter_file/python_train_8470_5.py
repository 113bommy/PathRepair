n=int(input())
for i in range(n+1,9999):
    s=str(i)
    if(s[0]!=s[1]!=s[2]!=s[3]and s[1]!=s[3]!=s[0]and s[0]!=s[2]):
        print(i)
        break
