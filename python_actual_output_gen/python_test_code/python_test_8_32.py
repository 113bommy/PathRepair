

for i in range(int(input())):
    s , a , b , c = map(int , input().split())
    p = s // (a * c)
    s = s - (p * a)
    print((p * a) + (p * b) + (s // c))
    