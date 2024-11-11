
n,m = map(int,input().split())
if m!=0:
 l = list(map(int,input().split()))
 l.sort()
 flag = 0

 if 1 in l or n in l:
    flag = 1

 for i in range(m-3):

    if l[i+1] - l[i] == 1 and l[i+2] - l[i+1] == 1:
        flag = 1
        break

 if flag == 1:
    print('NO')
 else:
    print('YES')

else:
  print('YES')



