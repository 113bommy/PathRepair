t = int(input())
for test in range (0,t) :
         n = int(input())
         lis = []
         tot = 1 
         day = 1
         while tot <= n :
                  lis.append(day)
                  day *= 2
                  tot+=day
         tot -= day         
         if(n>=tot) :
                  lis.append(n-tot) 
         lis.sort()   
         print(len(lis)-1)
         for i in range (1,len(lis)) :
                  print(lis[i]-lis[i-1],end=" ")
         print("")