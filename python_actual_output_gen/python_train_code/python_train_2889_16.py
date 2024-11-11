x=int(input())
for i in range(x,10**5+1):
    for j in range(2,i):
        if i%j==0:
            break 
    else:
         print(i)
         break
 