from collections import Counter

s = list(input())
k = int(input())

ans = 0
s_d = s*2
for i in range(1,len(s_d)):
    if s_d[i-1]==s_d[i]:
        s_d[i] = '_'
        if i>=len(s_d)//2:
            ans+=k-1
        else:
            ans+=1
s_s = set(s)
if len(s_s)==1 and len(s)%2!=0:
    ans = len(s)*(k//2)+(k%2==1)*(len(s)//2)
print(ans) 