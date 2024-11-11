q=int(input())
for x in range(q):
         n,d=list(map(int,input().split()))
         l=list(map(int,input().split()))

         res=l[0]
         i=1;j=0
         while(d>0 and i<len(l)):
                  if(d>=l[i]*i):
                           res+=l[i]
                           d-=l[i]*i
                  else:
                           res+=int(d/i)
                           break
                  i+=1
         print(res)