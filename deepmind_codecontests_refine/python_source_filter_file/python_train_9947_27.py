t,s,x = list(map(int, input().split(" ")))
if x<t:
   print("NO")
   exit()
elif ((x-t)%s==0) or ((x-t-1)%s==0 and (x-t-1)%s==0) or x==t  :
    print("YES")
else:print("NO")