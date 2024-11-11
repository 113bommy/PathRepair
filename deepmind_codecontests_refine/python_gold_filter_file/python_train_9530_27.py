bl=False
for _ in range(int(input())):
  ls=list(input().split())
  bl=True if int(ls[1])>=2400 and int(ls[2])>int(ls[1]) else bl
print('YES' if bl else 'NO')    
