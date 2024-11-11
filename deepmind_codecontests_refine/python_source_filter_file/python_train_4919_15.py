def main(n, s):
    if n > s: return "NO"
    res = "1 " * (n-1) + str(s - (n - 1))
    lst = set(range(n, s-1))
    for i in range(n, s):
        if (s - i) in lst:
            print("YES")
            print(res)
            return i
    return "NO"
    

n, s = [int(x) for x in input().split()]
print(main(n,s ))
            
    
    


