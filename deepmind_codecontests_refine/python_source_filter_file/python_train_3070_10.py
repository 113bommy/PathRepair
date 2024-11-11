s1= input().strip()
s2 = input().strip()
dist = 0
n = len(s1)
for i in range(n):
    if s1[i]!=s2[i]:
        dist+=1
if dist%2==1:
    print("impossible")
else:
    k = dist//2
    s = ""
    c =0
    for i in range(n):
        if s1[0]!=s2[0]:
            if c<=k:
                s=s+s1[i]
            else:
                s=s+s2[i]
            c+=1
        else:
            s=s+s1[i]
    print(s)
            