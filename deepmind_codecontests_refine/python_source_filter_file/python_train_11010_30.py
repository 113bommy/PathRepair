n = int(input())
c = 0

while n >= 100000:
   n -= 100000
   c += 1
   
while n >= 10000:
   n -= 10000
   c += 1

while n >= 1000:
   n -= 1000 
   c += 1


while n >= 100:
   n -= 100 
   c += 1

while n >= 20:
   n -= 20 
   c += 1
   
while n >= 10:
   n -= 10 
   c += 1
   
while n >= 5 :
   n -= 5 
   c += 1
   
while n >=1:
   n -= 1 
   c += 1

print(c)

   
