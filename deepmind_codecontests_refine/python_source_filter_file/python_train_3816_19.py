import re
r,c=map(int,input().split())
s='\n'.join(input().replace('.','D')for _ in[0]*r)
p='.'*(c+1)
print('No'if re.search('(S('+p+')?W)|(W('+p+')?S)',s)else'Yes\n'+s)