s,c=map(int,input().split())
if s > c*2:
   print(c//2)
   exit()
else:
   c-=s*2
s+=c//4
print(s)