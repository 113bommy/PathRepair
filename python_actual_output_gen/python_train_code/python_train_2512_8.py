n,s=map(int,input().split())
l=[]
cond=True
for i in range(n):
      x,y=map(int,input().split())
      l.append(x*60+y)
if l[0]>s:
      print("0 0")
      cond=False
else:
      for i in range(n-1):
            if l[i+1]-l[i]>=2*s+3:
                  cond=False
                  print((l[i]+s+1)//60 ," ",(l[i]+s+1)%60 ,sep="")
                  break
if cond :
      print((l[n-1]+s+1)//60," ",(l[n-1]+s+1)%60,sep="")

      
