n = int(input())
 
def fact(k):
    res = 1
    for i in range(2, int(k)+1):
        res *= i
    return res
    
print(str(int(fact(n)/(n/2)/(n/2)/2)))