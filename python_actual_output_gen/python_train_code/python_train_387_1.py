no_of_cowbell,no_of_boxe=map(int,input().split())
li1=list(map(int,input().split()))
cows_packed=no_of_boxe*2
if(no_of_cowbell==no_of_boxe):
          print(li1[no_of_cowbell-1])
else: 
    j=no_of_cowbell-1
    ans=li1[no_of_cowbell-1]
    if(no_of_cowbell-no_of_boxe>0):
           j=(no_of_cowbell-no_of_boxe)*2-1
    i=0       
    while(i<j):
          if(li1[i]+li1[j]>ans):
                  ans=li1[i]+li1[j]
          i+=1 
          j-=1 
    print(ans)          
        
          
           
               
    