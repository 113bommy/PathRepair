n = int(input())
alist = [input() for i in range(n)]
 
if len(set(alist))==n:
  if all(alist[i][-1]==alist[i+1][0] for i in range(n-1)):
    print("Yes")
  else:
    print("No")