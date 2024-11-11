n=int(input())
ki=input()
if len(ki)==len(set(ki)) and len(ki)>1:
 print('NO')
else:
 print('YES')