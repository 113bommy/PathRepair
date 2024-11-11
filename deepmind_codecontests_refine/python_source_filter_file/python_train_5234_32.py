a = int(input())
for i in range(a):
    b,c = map(int,input().split())
    print((c-b%c)%b)