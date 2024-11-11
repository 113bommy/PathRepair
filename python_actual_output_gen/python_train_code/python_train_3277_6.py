n = int(input())
 
def fact(k):
    res = 1
    for i in range(2, int(k)+1):
        res *= i
    return res
    
print(str(int(fact(n)/fact(n/2)/fact(n/2)/2)))