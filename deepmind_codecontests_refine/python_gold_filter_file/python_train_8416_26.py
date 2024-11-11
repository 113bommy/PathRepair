s=input().split()
n=int(s[0])
x=int(s[1])
s=input().split()
ans=max(0,int(s[0])+int(s[1])-x)
prev=max(0,int(s[1])-ans)
for i in range(2,len(s)):
 now=max(0,int(s[i])+prev-x)
 ans+=now
 prev=int(s[i])-now
print(ans)