import re
t='abacaba'
for s in[*open(0)][2::2]:
 i=0;f=1;r=t+t
 while f and r.find(t)<r.rfind(t):r,f=re.subn(''.join(rf'({x}|\?)'for x in t),t,s[i:],1);r=s[:i]+r;i=r.find(t,i+1)
 print(*(['NO'],['YES',r.replace('?','d')])[f])