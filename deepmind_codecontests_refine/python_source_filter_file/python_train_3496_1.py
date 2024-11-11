arr=list(map(int,input().split()))
n = str(arr[0])
k = arr[1]
s = ''
zer_kolvo = 0
count = 0
s_s = n
if k >= len(n):
  print(len(n)-1)
elif n.count('0') < k:
  print(len(n)-1)
else:
  sch = 0
  n_c = n[::-1]
  for i in n_c:
    if i != '0':
      s_s = n[0:len(n)-sch]
      count += 1
      #print(s_s)
    else:
      s_s = n[0:len(n)-sch]+'0'*zer_kolvo
      zer_kolvo += 1
      print(s_s)
    sch += 1
    if int(s_s)%(10**k) == 0:
        print(count)
        break
    
      
  