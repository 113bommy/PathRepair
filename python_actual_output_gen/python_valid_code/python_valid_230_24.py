n,x,y=map(int,input().split())
arr=list(map(int,input().split()))
if(x>y):
    print(n)
else:
   count=0
   ans=0
   for i in range(n):
       if(x>=arr[i]):
           count+=1
   if(count%2==1):
       ans+=1
   ans=count//2
   print(ans)
