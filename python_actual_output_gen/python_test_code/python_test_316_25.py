
s = (input())
ans = 0
mp = {'a':1,'e':1,'i':1,'o':1,'u':1}
for i in range(len(s)):
    if s[i].isalpha():
        if s[i] in mp:
            ans+=1
    else:
        if (int(s[i]))&1 == 1:
            ans+=1
            print(s[i])

print(ans)
