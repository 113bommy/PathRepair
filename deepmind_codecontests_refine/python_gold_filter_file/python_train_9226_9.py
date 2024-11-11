# submitted from train through mobile
for _ in range(int(input ())):
 n = int(input())
 
 ans = "NO"
 for i in range(n) :
  Rem = n - 3*i
  if(Rem%7 == 0 and Rem>=0): ans = "YES"
 print(ans)