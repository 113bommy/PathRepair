s = str(input())

if s[-1] == s[0]:
  if len(s)%2 == 0:
    print("First")
  else:
    print("Second")
  

else:
  if len(s)%2 == 1:
    print("First")
  else:
    print("Second")
