a=input()
b=input()
c=input()
nx = (a+b+c).count('X')
no = (a+b+c).count('0')
n = (a+b+c).count('.')
ls=[a,b,c]
for i in range(3):
   ls.append(a[i]+b[i]+c[i])
ls.append(a[0]+b[1]+c[2])
ls.append(a[2]+b[1]+c[0])
p = 'XXX' in ls
q = '000' in ls
diff = nx-no
if (p and q) or diff<0 or (diff > 2) or (q and diff>0) or (p and diff==0):
   print("illegal")
elif p:
   print("the first player won")
elif q:
   print("the second player won")
elif nx+no >=9:
   print("draw")
elif diff==1:
   print("second")
else:
   print("first")