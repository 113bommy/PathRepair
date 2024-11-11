s=input()
if len(s)<26:
    al=[chr(ord('a') + i) for i in range(26)]
    for i in al:
        if not(i in s):
            print(s+i)
            exit()
if s=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
    exit()
for i in range(25):
    if s[i]>s[i+1]:
        k=i-1

a="z"
for i in range(k+2,26):
    if s[k+1]<s[i]:
        a=min(a,s[i])
print(s[:k]+a)