# Author:      Divesh Uttamchandani
# Institution: BITS Pilani
s = input()

n = len(s)
ans = 0
for i in range(n):
    for j in range(i,n):
        if(s[i:j]!=s[i:j][::-1]):
            #print(s[i:j])
            #print(j-i)
            ans = max(j-i, ans)
print(ans)



# <> with <3 using Termicoder:
# https://termicoder.github.io
