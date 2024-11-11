t = int(input())
for i in range(t):
    s, a, b, c = [int(i) for i in input().split()]
    print(s//c + s//a*b)