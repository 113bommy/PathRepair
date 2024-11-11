a , b = map(int,input().split())
if b > a :
    ans = 0
    while True :
        if b % 2 == 0 : b /= 2 ; ans += 1
        else : b +=1 ; ans += 1
        if b == a : print(ans) ; break
        elif b < a : print( int(ans + a - b) )
else : print(a-b)
    
