n = input()
arr = map(int,input().split())
for y in arr:
  if y > 14:
       x = y
       z = x//14
       x = x-z*14
       
       if(x<15):x=x+14
       
       if(x>=15 and x<21):
           print("YES")
       else:
           print("NO")    
  else: print ("YES")