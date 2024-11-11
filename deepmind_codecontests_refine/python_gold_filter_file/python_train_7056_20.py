s=input()
q=int(input())
order=1
header=''
footer=''
for _ in range(q):
  tmp=input()
  if tmp=='1':
    order*=-1
  else:
    t, f, c=tmp.split()
    if (int(f)*order)%3==1:
      header=c+header
    else:
      footer=footer+c
s=header+s+footer
print(s) if order==1 else print(s[::-1])