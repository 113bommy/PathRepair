s = intput()
for i in range(1,n):
  if s[i] == s[i-1]:
    print('Bad')
    exit()
print('Good')