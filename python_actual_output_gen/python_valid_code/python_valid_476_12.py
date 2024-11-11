def closingGap(n,a):
    total = 0    
    for i in a:
        total += 1
    
    if(total%n == 0):
        return 0
    else:
        return 1
 
if __name__ == '__main__':
    t = int(input())  #no. of test cases
    for i in range(t):
        n = int(input())    #no. of buildings
        a = list(map(int, input().split()))
        result = closingGap(n,a)
        print(result)