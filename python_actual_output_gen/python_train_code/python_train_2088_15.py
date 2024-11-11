def best_possible(n):
    temp = ''
    if n%2==0:
        temp = '11'* (n//2)
    else:
        temp = '7'+ '11'*( (n-3)//2 )
    return temp
    
for _ in range(int(input())):
    print(best_possible(int(input())))