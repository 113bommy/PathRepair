import sys

s = input()
for l in range(len(s)) :
      for r in range(l,len(s)) :
            if s[:l]+s[r:]=='CODEFORCES' :
                  print('YES')
                  sys.exit(0)
print('NO')
