#Cupboards
#Problem Link : http://codeforces.com/problemset/problem/248/A

n = int(input())
leftOne , rightOne = 0 , 0
for _ in range(n):
    x , y = map(int , input().split())
    leftOne += x
    rightOne += y

print(n - leftOne if leftOne > n // 2 else leftOne + n - rightOne if rightOne > n // 2 else rightOne)
