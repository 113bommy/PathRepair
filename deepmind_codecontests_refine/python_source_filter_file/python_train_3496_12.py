def solve(n,i) :
    removed = 0
    zero = 0
    for x in n[::-1] :
        if zero == i :
            return removed
        if x != "0" :
            removed += 1
        else :
            zero += 1
    
    
    return (zero - (zero-1)) + removed


n,i = input().split()
  
print (solve(n,int(i)))