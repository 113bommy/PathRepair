x,y = map(int,input().split())
n = int(input())
a = [x, y, (x-y)*(-1), -x, -y, ((x-y)*(-1))*(-1)]
print(int(a[n%6]%1000000007))
