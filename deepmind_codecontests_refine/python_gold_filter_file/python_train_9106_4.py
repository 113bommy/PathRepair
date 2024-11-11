s = str(input())
n = int(input())
l = []
if(len(s) % n != 0):
  print("NO")
  exit()
for i in range(0,len(s),(len(s) // n)):
  t = s[i:i+(len(s) // n):]
  for j in range(len(t)):
    if  t[::] != t[::-1]:
      print("NO")
      exit()
print("YES")
 


