def gcd(x , y):
    if(x > y):x , y = y , x
    if(x == 0):return y
    return gcd(y % x , x)
A , B = map(int , input().split())
def solve(X , Y):
    if(X > Y):
        if(Y == 1):
            print(str(X - 1) + "A" , end = "")
            return;
        else:
            print(str(X // Y) + "A" , end = "")
            solve(X % Y , Y)
    else:
        if(X == 1):
            print(str(Y - 1) + "B" , end = "")
            return;
        else:
            print(str(Y // X) + "B" , end = "")
            solve(Y % X , X)
if(gcd(A , B) == 1):
    solve(A , B)
else:
    print("Impossible")
