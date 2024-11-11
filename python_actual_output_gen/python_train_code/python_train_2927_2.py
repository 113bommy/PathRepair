s=input()
t=input()

ans=0
s_inx=0
t_inx=0
s_l=len(s)
t_l=len(t)

c=0
while t_inx<=t_l-1:
  try:
    temp_inx=s[s_inx:].index(t[t_inx])
    s_inx+=temp_inx+1
    t_inx+=1
    c=0
  except:
    c+=1
    s_inx=0
    ans+=s_l

  if c==2:
    print(-1)
    exit()
else:
  ans+=s_inx+1

print(ans)