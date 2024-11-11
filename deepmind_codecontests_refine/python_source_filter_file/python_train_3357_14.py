t=int(input())
while t>0:
       a,b=map(int,input().split())
       sol=(b/(a-1))*a + (b%(a-1))
       if(b%(a-1)==0):
              sol=sol-1
       print(sol)
       t=t-1