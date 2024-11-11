def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
    
def loadinput():
   nu = int(input())
   return nu
def getSum(n):  
     
    sum = 0
    for digit in str(n):   
      sum += int(digit)        
    return sum
def findcount(nu):
    count =0 
    if nu <= 9 :
        return 0
    else:
        while nu > 9:
            nu = sum(map(int, str(nu)))
            count+=1
    return count          
if __name__ == '__main__':
    nu = loadinput()
    count = findcount(nu)
    print(count)