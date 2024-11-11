n,a,b,c = input ().split()
n=int(n)
resto=4-(n%4)
if resto==4:
  print(0)
elif resto==1:
  print(min([int(a),int(b)+int(c), int(c)*3 ]  ) )
elif resto==2 :
  print(min([int(a)*2, int(b), int(c)*2]))
else : 
  print(str(min([int(a)*3, int(a) +int (b) , int (c)])))