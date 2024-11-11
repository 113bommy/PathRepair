def Encoding(x):
    l = list()

    #first digit
    if x[0] == '1':
        l.append(1)

    #loop on all after first digit
    for i in range(1, len(x)):

        if x[i] == '0': #if current digit is zero, pass
            continue
        elif x[i] == '1' and x[i-1] == '0': #if current digit is the start of a new segment
            l.append(1)
        else: #current digit is a coninuation of an old segment
            l[len(l)-1] += 1
    
    return l

##########################

def generatePrintBinary(n):
     
    # Create an empty queue
    from queue import Queue
    q = Queue()
     
    # Enqueu the first binary number
    q.put("1")
 
    # This loop is like BFS of a tree with 1 as root
    # 0 as left child and 1 as right child and so on
    while(1):
        n-= 1
        # Print the front of queue
        s1 = q.get() 
        if int(s1) / int(n) > 1:
            return
        #print(s1)
     
        s2 = s1 # Store s1 before changing it
     
        # Append "0" to s1 and enqueue it
        q.put(s1+"0")
 
        # Append "1" to s2 and enqueue it. Note that s2
        # contains the previous front
        q.put(s2+"1")

##########################

count = 0


n, x = map(int, input().split(" "))
a = list(map(int, input().split(" ")))

#current logic says i have to make sure all segments are only seperated by one zero
#if there is more than one zero between segments then it is not unique
#no need to compensate for leading or trailing zero because
#encoding logic ignores them

count = -1
for y in a:
    count += 1+y
    #print("adding",y+1,"to a total of",count)


if count == x :
    print("YES")
else:
    print("NO")

#generatePrintBinary(10)
