import sys
input=sys.stdin.readline
n,m=map(int,input().split())
x,k,y=map(int,input().split())
a=[int(i) for i in input().split() if i!='\n']
b=[int(i) for i in input().split() if i!='\n']
count,ind,maxa=0,0,0
store,prefmax=[],[]
for i in range(len(a)):
     try:
          #print(a[i],b[ind])
          if a[i]==b[ind]:
               count+=1
               store.append([a[i],i])
               prefmax.append(max(maxa,a[i]))
               maxa=a[i]
               ind+=1
          else:
               maxa=max(maxa,a[i])
               prefmax.append(maxa)
     except:
          maxa=max(maxa,a[i])
          prefmax.append(maxa)
          pass
if b[-1]!=a[-1]:
     store.append([a[-1],n])
     prefmax.append(maxa)
ok=0
if b[0]!=a[0]:
     store.insert(0,[a[0],-1])
     prefmax.insert(0,a[0])
     ok=1
if count!=m:
     print(-1)
     exit()
else:
     ans=0
     #print(prefmax,store)
     optimum=0
     if x>y*k:
          optimum=1
     for i in range(1,len(store)):
          diff=(store[i][1]-store[i-1][1]-1)
          if prefmax[max(0,store[i][1])+ok]>max(store[i][0],store[i-1][0]):
               if diff<k and diff>0:
                    print(-1)
                    exit()
               else:
                    if optimum:
                         ans+=((diff-k)*y+x)
                    else:
                         ans+=((diff//k)*x+(diff%k)*y)
          else:
               if optimum:
                    ans+=(diff*y)
               else:
                    #print(diff,i)
                    ans+=((diff//k)*x+(diff%k)*y)
     print(ans)
               
                    
     
     
          
