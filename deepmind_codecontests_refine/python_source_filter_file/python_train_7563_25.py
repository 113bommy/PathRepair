n = int(input())
c=0
if(n == 0):
    c = n
elif(n % 2 == 0):
   c = n+1
else:
    c = (n+1)/2
print(c)