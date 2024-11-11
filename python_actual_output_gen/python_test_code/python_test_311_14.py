z=int(input())
n=input().split()
for i in range(z):
 n[i]=int(n[i])
n=list(set(n))
n.sort()
l=len(n)
for i in range(l):
   if i+1+3>l:
      print("NO")   
      break 
   if n[i]+1==n[i+1]:
        if n[i+1]+1==n[i+2]:
            print("YES")
            break
else:
       print("NO")  