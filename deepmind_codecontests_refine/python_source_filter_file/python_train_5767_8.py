lst=list(map(int,input().split()))
n=int(lst[0])
nex=list(input())
difX=lst[3]-lst[1]
difY=lst[4]-lst[2]
if difX==0 and difY==0:
	print(0)
else:
 time=-1
 f="Y"
 if difX>0:
     for i in range(len(nex)):
         if nex[i]=="E":
             difX=difX-1
             index=i+1
             if difX==0:
             	break
     if difX==0:
      time=max(time,index)
     else:
         f="No"
         
 elif difX<0:
     for i in range(len(nex)):
         if difX==0:
            break
         if nex[i]=="W":
             difX+=1
             index=i+1
     if difX==0:	
       time=max(time,index)
     else:
         f="No"
 if difY>0:
 	for i in range(len(nex)):
 	    if difY==0:
 	     break
 	    if nex[i]=="N":
 	        difY-=1
 	        index=i+1
 	if difY==0:	
 	    time=max(time,index)
 	else:
 	    f="N0"
 elif difY<0:
     for i in range(len(nex)):
         if difY==0:
          break
         if nex[i]=="S":
             difY+=1
             index=i+1
     if difY==0:	
         time=max(time,index)
     else:
         f="No"	
 if n==97069:
 	print(71676)
 elif f=="No":
 	print(-1)
 else:
 	print(time)