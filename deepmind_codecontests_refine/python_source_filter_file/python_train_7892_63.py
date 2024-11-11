a,b,c = map(int,input().split())
k = int(input())
x = max(a,b,c)
print(a+b+c+x*2*k-x)