def In8(A):
   if '8' in str(A):
      return True
   return False
A=int(input())
Output=0
while In8(A):
   A+=1
   Output+=1
def Main(A):
   for I in range(8888888888-A):
      if In8(A+I):
         return(I)
Output+=Main(A)
print(Output)
