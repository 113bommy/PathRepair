T = int(input())
for case in range(T):
  n = int(input())
  arr = []
  for i in range(n):
    arr.append(input())
  ans =0
  flag =True
  for i in range(5):
    ele = []
    cyes=0
    cno=0
    for s in arr:
      yes= s.count(chr(i+ord('a')))
      no = len(s)-yes
      ele.append((yes,no))
      cyes+=yes
      cno+=no
    ele.sort(key = lambda x:[x[1]-x[0]])
    if cyes>cno:
      print(n)
      flag =False
      break
    for i in range(len(ele)-1,-1,-1):
      cyes -= ele[i][0]
      cno -= ele[i][1]
      if cyes>cno:
        ans = max(ans,i)
  if flag:
      print(ans)

      