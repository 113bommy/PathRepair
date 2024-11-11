for _ in range(int(input())):
    n = int(input())
    a = n%3
    c1 = n // 3 + a
    c2 = n//3
    if a == 2:
        c2+=1
        c1-=1
    print(c1,c2)