n=int(input())
s=input()
res=0
x=''
for i in range(n-1):
    cur=0
    for j in range(n-1):
        if s[j]==s[i] and s[j+1]==s[i+1]:
            cur+=1
    if res<cur:
        res=cur
        x+=s[i]+s[i+1]
print(x)
        