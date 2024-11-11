
def solve(l1,l2,l3):
     ai=0
     ci=0
     r=10**100+1
     for i in range(0,len(l2)):
          if(ai<len(l1) and l1[ai]<l2[i]):
              ai+=1
          if(ci<len(l3) and l3[ci]<l2[i]):
               ci+=1
          if(ci==len(l3)):
               ci-=1
          if(ai==0):
               ai+=1
          r=min(r,(l1[ai-1]-l2[i])**2+(l2[i]-l3[ci])**2+(l1[ai-1]-l3[ci])**2)
     return r
          
               
t=int(input())
for i in range(t):
     ans=10**100+1
     r,g,b=input().split()
     r=int(r)
     b=int(b)
     g=int(g)
     l1=list(map(int,input().split()))
     l1.sort()
     l2=list(map(int,input().split()))
     l2.sort()
     l3=list(map(int,input().split()))
     l3.sort()
     ans=min(ans,solve(l1,l2,l3))
     ans=min(ans,solve(l1,l3,l2))
     ans=min(ans,solve(l2,l1,l3))
     ans=min(ans,solve(l2,l3,l1))
     ans=min(ans,solve(l3,l1,l2))
     ans=min(ans,solve(l3,l2,l1))
     print(ans)
