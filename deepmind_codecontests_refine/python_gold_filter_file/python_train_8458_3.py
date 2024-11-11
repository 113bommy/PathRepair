n = int(input())
for i in range (n):
    s = int(input())
    s1  =  list(map(int,input().split()))
    s2 = set (s1)
    print (*s2)