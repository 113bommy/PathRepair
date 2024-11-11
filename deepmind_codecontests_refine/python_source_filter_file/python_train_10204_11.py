n=int(input())
l=list(map(int, input().split()))
for i in range(n):
    l[0:i]=sorted(l[0:i])
    print(l)