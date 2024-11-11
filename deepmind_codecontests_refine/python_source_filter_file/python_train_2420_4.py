for _ in range(int(input())):
    n = int(input())
    s1 = 2**n
    s2 = 2**(n//2)
    for i in range(1,(n//21)):
        s1 = s1 + (2**i)
    for j in range((n//2 +1),n):
        s2 = s2+(2**j) 
    print(s1-s2)

