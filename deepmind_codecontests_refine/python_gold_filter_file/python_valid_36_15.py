def rl():
    return [int(w) for w in input().split()]
 
for _ in range(int(input())):
    n = rl()[0]
    if n == 1:
        print("a")
    elif n == 2:
        print("ab")
    elif n == 3:
        print("abc")
    elif n % 2 == 0:
        k = (n-1)//2 + 1
        print("a"*k+"b"+"a"*(k-1))
    elif n % 2 == 1:
        k = (n-2)//2 + 1
        print("a"*k+"bx"+"a"*(k-1))
        