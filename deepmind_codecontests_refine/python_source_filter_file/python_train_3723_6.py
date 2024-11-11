def itoa(x, base) :
    negative = False
    s = ""
    if (x == 0) :
        return "0"
    negative = (x < 0)
    if (negative) :
        x = -1 * x
    while (x != 0) :
        s = str(x % base) + s 
        x = int(x / base) 
     
    if (negative) :
        s = "-" . s
 
    return s
 
def binaryGenerator(n,uplim) :
    numofnum=0
    for i in range(1, n + 1) :
        numofnum+=1
        i+=1
        if(int(itoa(i,2))>uplim):
           break
    return numofnum
uplimstr=input()    
uplim=int(uplimstr)
n = len(uplimstr)+10
print(binaryGenerator(n,uplim))