
def g():
    
    
    n = int(input())
    l = [int(x) for x in input().split()]
    
    for i in range(n-1):
        
        for j in range(i+1,n):
            
            if(l[i] == l[j-1]):
                return("YES")
    return("NO")
    
test_case = int(input())
for ___ in range(test_case):
    print(g())