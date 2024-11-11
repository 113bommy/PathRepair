k,n=map(int,input().split())
s=input()
z=[0]*26
z2 = [0]*26
for i in s:
    z[ord(i)-97]+=1
for i in range(26):
    m = min(n, z[i])
    n -= m
    z2[i] = m
s2=['']*len(s)
for i in range(len(s)):
    if z2[ord(s[i])-97]:
        z2[ord(s[i])-97]-=1
    else:s2[i]=s[i]
print(s2)