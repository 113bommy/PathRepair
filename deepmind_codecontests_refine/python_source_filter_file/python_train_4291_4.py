from math import sqrt
n=int(input())
s=[i for i in input()]
if (s.count('W'))%2 and (s.count('B'))%2:print(-1);exit()
else:
  i=0;ans=[]
  if s.count('B')%2==0:
     while i<n-1:
       if s[i]=='B':
        ans.append(i+1)
        if s[i+1]=='W':s[i+1]='B'
        else:s[i+1]='W'
       i+=1
    # print(s)
  else:
     i=0;ans=[]
     while i<n-1:
       if s[i]=='W':
        ans.append(i+1)
        if s[i+1]=='W':s[i+1]='B'
        else:s[i+1]='W'
       i+=1
  print(ans)
  print(len(ans))
  if len(ans)!=0:print(*ans)
