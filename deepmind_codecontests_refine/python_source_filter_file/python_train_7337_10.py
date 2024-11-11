n=int(input())
s=input()
b=[-1]*256
c=[]
for i in range(len(s)):
    if b[ord(s[i])]==-1:
        b[ord(s[i])]=i
        c.append(i)
print(c)
if len(c)>=n:
    print("YES")

    for i in range(n):
        if i<n-1:
            print(s[c[i]:c[i+1]])
        else:
            print(s[c[i]:])
else:
    print("NO")
