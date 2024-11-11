import re
r,c=input().split()
s='\n'.join(input().replace('.','D')for _ in[0]*int(r))
print('No'if re.search('(?s)(S.{'+c+'}?W)|(W.{'+c+'}?S)',s)else'Yes\n'+s)