s=input()
c=s.count('VK')
s=s.replace('VK', '')
print(c+1 if s.count('VV') or s.count('KK') else c)