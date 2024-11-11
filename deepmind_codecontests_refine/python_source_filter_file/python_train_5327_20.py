n=int(input())
for i in range(n):
    a,b,c = (int(x) for x in input().split())
    print(a-min(b,c))