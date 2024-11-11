'''
Name : Jaymeet Mehta
codeforces id :mj_13
Problem : 
'''
from sys import stdin,stdout
n=int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]
a.sort()
cnt=(n-1)//2
l,r=0,n//2
ans=[]
while(l<n//2):
    ans.append(a[r])
    ans.append(a[l])
    l+=1
    r+=1
if n&1:
    ans.append(a[-1])
print(cnt)
print(*ans)