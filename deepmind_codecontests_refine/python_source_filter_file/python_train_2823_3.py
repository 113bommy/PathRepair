trump = input()
x = input()
x = x.split()
mp = {'6':6,'7':7,'8':8,'9':9,'T':10,'J':11,'Q':12,'K':13,'A':14}
if(x[0][1] == x[1][1]):
  if(mp[x[0][0]] > mp[x[1][0]]):
    print('Yes')
  else:
    print('No')
else:
  if(x[0][1] == trump):
    print('Yes')
  else:
    print('No')
