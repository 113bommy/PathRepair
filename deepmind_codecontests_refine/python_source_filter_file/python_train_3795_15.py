n=int(input())
c=1
for i in range((n//2)+1):
   for j in range(i,n//2):
       print("*",end=" ")
   for j in range(c):
       print("D",end=" ")
   for j in range(i,n//2):
       print("*",end=" ")
   c=c+2
   print()
c=c-4
x=n-((n//2)+1)
for i in range(x):
    for j in range(i+1):
        print("*",end=" ")
    for j in range(c):
        print("D",end= " ")
    for j in range(i+1):
        print("*",end=" ")
    c=c-2
    print()
