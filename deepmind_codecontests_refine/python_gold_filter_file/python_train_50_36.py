n ,m = map(int,input().split())
s = []
for i in range(n):
   s.append(input().split())
l = set()
for j in range(n):
   l = l | set(s[j][1:]) 
if len(l) == m :
   print('YES')
else:
   print('NO')