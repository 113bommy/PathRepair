t=int(input())
while(t):
     n=int(input())
     l=list(map(int,input().split()))
     odd=0
     even=0
     for i in l:
         if(i%2!=0):
             odd+=1
         else:
             even+=1
     if odd==0 or even==0 or n%2==0:
             print("NO")
     else:
        print("YES")
             
     t=t-1