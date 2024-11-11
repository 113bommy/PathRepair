n = int(input())
for i in range(n):
    a,b,c,d = map(int,input().split())
    print(min(2*c-a,a+b))