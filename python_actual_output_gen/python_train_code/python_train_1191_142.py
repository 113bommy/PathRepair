def solv():
    a,b,c,d=map(int,input().split())
    print(b,c,c+(d>c))

t=int(input())
for i in range(t): solv()
