a=0
x=list(map(int,input().split()))
lst=list(map(int,input().split()))
#print('lst=',lst)
v=lst.count(1)
c=lst.count(2)
#print('c=',c)
if x[1]-v<=0:
    a+=v-x[1]
    x[1]=0
   # print('a=',a)
else:
   #print('gggggggggggg')
   x[1]=x[1]-v 
   #print('x[1]*******',x[1])   
 
    #print('x[2]=%d    x[1]=%d     c=%d'%(x[2],x[1],c))
if x[2]+x[1]-c<0:    
    a+=abs(x[2]+x[1]-c)
   # print('aaaaaaaaa=',a)
print(a)

#1 2 2   2