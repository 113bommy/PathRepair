n,a,b=map(int,input().split())
l=list(map(int,input().split()))
ans=0
ca=a
cb=b
for i in range(n):
         if(l[i]==0):
                  if(ca>0):
                           ca-=1
                  else:
                           if(cb>0):
                                    cb-=1
                           else:
                                    break
         else:
                  if(ca<a and cb>0):
                           cb-=1
                           ca+=1
                  else:
                           if(ca>0):
                                    ca-=1
                           elif(cb>0):
                                    cb-=1
                           else:
                                    break
         #print(ca,cb)
         ans+=1
print(ans)