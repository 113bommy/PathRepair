x=str(input())
s=len(x)
count_love=0
for love in range(0,s,1):
     if x[love] == 'a' :
         count_love+=1

if count_love>s/2:
 print(s)
else:
    print(2*count_love-1)