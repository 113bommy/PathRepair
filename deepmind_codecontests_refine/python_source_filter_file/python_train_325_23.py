n,x,y=map(int,input().split())
s=input()
s=s[-x:]
print(s)
ans=s.count('1')
if s[-y-1]=='1':
    print(ans-1)
else:
    print(ans+1)