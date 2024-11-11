a = int(input())
for i in range(9):
  if(a%(i+1) ==0 and a/(i+1)<=9):
    print("Yes") 
    exit()
print("No")  