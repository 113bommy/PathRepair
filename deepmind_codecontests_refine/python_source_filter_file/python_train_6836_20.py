
m,n=map(int,input().split())
a=list(map(int,input().split()))
b=set(a)
b=list(b)
finalarr=[]
if len(b)>=n:
   print("YES")
   for i in range(len(b)):
      for j in range(len(a)):
         if b[i]==a[j]:
            finalarr.append(j+1)
            break
         else:
            continue
   finalarr.sort()
   print(*finalarr)
else:
   print("NO")
   

