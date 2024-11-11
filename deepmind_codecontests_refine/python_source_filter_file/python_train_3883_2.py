#import io,os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
import heapq

 
T = int(input())
r = 1
 
 
while r<=T:
    n = int(input())
    arr = list(map(int,input().split()))

#    arr = [1,2]*50000+[1,3,1,2]+[1,2]*49998
#    n = 200000

    third = [0]*n
    third[-1] = arr[-1]
    maxfre = 0
    for i in range(n-2,-1,-1):
        third[i] = max(third[i+1],arr[i])

    firstdic = {}
     
 

    temp = []
    secondindexnum = 0
    secondindexmin = 2147483647

    flag = False

    fuck = 0
 
    for i in range(n-1):
        if i%100==0: print(i)
        if arr[i]<=third[i+1]: 
            heapq.heappush(temp,[-arr[i],-i]) 
        else:
            secondindexnum += 1
            secondindexmin = min(secondindexmin,i)



        while temp and -temp[0][0]>third[i+1]:
            ele = heapq.heappop(temp)
            secondindexnum += 1
            secondindexmin = min(secondindexmin,-ele[1])
           
#        print(temp,secondindexmin,secondindexnum)


 
        if len(temp)<2: continue
        if temp[0][0]!=-third[i+1]: continue
        maximum = heapq.heappop(temp)
        if temp[0][0]!=-third[i+1]:
            heapq.heappush(temp,maximum)
            continue    
        heapq.heappush(temp,maximum)   

 
        if secondindexnum==0:
            flag = True
            x,y,z = len(temp)-1,1,n-len(temp)
            break   
        needed = i - secondindexmin + 1 - secondindexnum
        if len(temp)<needed+1: continue


#        print("hahaha",needed)
 

        if needed==0 and -temp[0][1]==secondindexmin-1:
            flag = True
            x,y,z = secondindexmin-1,i+2-secondindexmin,n-i-1
            break


        if needed>0 and len(temp)>needed:
            extra = []
            fuck += 1

            if fuck>1000: break
              


            while -temp[0][0]==third[i+1] and -temp[0][1]>secondindexmin:
                extra.append(heapq.heappop(temp))
                if len(extra)==needed and temp and -temp[0][0]==third[i+1]:
                    flag = True
                    x,y,z = secondindexmin,i+1-secondindexmin,n-i-1
                    break


#            print(extra)

#            if len(extra)>1000: 
#                print(len(extra))
#                err = [1,2,3]
#                print(err[4])
            while extra:
                heapq.heappush(temp,extra.pop())

            
   

 
 
        
 
        
    if flag:
        print("YES")
        print(x,y,z) 
    else:
        print("NO")       
 
        
 
        
    
 
 
 
 
 
 
 
 
     
 
 
 
    r += 1
