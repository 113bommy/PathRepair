N=int(input())
for i in range(9):
  if N%(i+1)==0 and N/(i+1)<=9 :
    print("Yse")
    break
else :
  print("No")