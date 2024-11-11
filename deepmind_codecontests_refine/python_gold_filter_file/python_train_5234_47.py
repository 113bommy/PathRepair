n = int(input())

for i in range(n):
    a,b = map(int,input().split())
    k = a
    q = b
    N = 0
    if a%b==0:
        print(0)
    else:
        print(b-a%b)
        
    