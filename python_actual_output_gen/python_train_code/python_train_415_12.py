t=int(input())
for i in range(t):
    #l=[]
    a=0
    b=0
    n,m,x,y=map(int,input().split())
    for j in range(n):
        #l1=list(map(int,input().split("")))
        #l.append(l1)
        s=input()
        a+=s.count('.')
        b+=s.count('..')
    #for j in l:
     #   for k in range(1,m):
      #      if(j[0]=='.'):
       #         a+=1
        #    if(j[k]=='.'):
         #       a+=1
          #  if(j[k-1]=='.' and j[k]=='.'):
           #     b+=1
    if(y>2*x or b==0):
        print(x*a)
    else:
        print(int(y*b+x*((a/2)-b)))
