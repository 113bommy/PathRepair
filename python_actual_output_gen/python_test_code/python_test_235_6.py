def solve():
    a, m = map(int, input().split())
    reached = [False]*m

    for i in range(m):
        if a == 0:
            return("Yes")
        else:
            a = (a*2)%m
            
    return "No"
    
print(solve())