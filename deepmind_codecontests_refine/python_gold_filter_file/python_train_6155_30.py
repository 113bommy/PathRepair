n = int(input())
x,y = map(int,input().split())
print(['Black','White'][x+y<=n+1])