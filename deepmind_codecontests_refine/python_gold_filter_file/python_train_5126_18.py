t=int(input())
for i in range(t):
     n,x=input().split()
     n=int(n)
     x=int(x)
     a=list(map(int,input().split()))
     ctr1=1
     ctr=0
     for i in range(1,n+x+1):
         if i not in a:
             a.append(i)
             ctr+=1
         if ctr==x:
             break
     while(True):
         if ctr1 in a:
             ctr1+=1
         else:
             print(ctr1-1)
             break