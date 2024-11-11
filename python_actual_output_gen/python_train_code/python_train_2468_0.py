m = int(input())
sp = 40000
answer = True
dist = 0
for i in range(m) :
  a, b = input().split()
  if dist == 0 and b[0] != 'S' : 
    answer = False
  if dist == sp and b[0] != 'N' : 
    answer = False
  if b[0] == 'S' : dist += int(a)
  if b[0] == 'N' : dist -= int(a)
  if dist > sp or dist < 0 : 
    answer = False

answer = answer and dist == 0
print( "YES" if answer else "NO")
