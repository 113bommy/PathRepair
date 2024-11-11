# your code goes here

n,k = input().split()
#k = input()
#print(n)
#print(k)
n = int(n)
k = int(k)
l = [int(i) for i in input().split()]

#print(l)
  
i = 0
mid = 0
#print(len(l))

while(len(l) > 0):
    #print i 
    #print len(l)-1
    if(l[i] <= k):
       # print l[i]
        l.pop(i)
        if(mid == 1): 
            i = len(l)-1	
        #print l
    elif(l[i] > k and mid == 1):
        break
    else:
        mid = 1
        i = len(l)-1
        
#print l
#print n
print(n-len(l))