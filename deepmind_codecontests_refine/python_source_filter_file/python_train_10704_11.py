n=int(input())
s=input()

e=0
w=0

all_e=s.count("E")
ans=float('inf')
for i in range(n):

  ans=min(all_e-e+w,ans)

  if s[i]=="E":
    e+=1
  else:
    w+=1

ans=min(ans,all_e+w,ans)
print(ans)