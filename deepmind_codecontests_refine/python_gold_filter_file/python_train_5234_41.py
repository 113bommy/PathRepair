a = int(input())
for a in range(a):
    b,c = map(int,input().split())
    print((c-b%c)%c)