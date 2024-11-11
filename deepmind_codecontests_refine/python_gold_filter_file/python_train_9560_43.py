A, B = map(int,input().split())
n=0
for i in range(A,B+1):
  s = str(i)
  if s[0]==s[4] and s[1]==s[3]:
    n+=1
print(n)