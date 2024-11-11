u1, u2=map(int, input().split())
t, d=map(int,input().split())
if u1 > u2:
    u1,u2=u2,u1 
s = [u1 for i in range(t-1)]
s.append(u2)
l=1
r=t-2
for i in range(t-2, 0, -1):
    s[i]=s[i+1]+d
i =1
while s[i] -s[i-1]>d:
    s[i]=s[i-1]+d
print(sum(s))