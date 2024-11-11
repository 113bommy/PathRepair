N = int(input())
flag = True
for i in range(N):

    t,x,y = map(int, input().split(" "))

    if x+y>t or t%2 !=(x+y)%2:
        flag=False
        break

print("Yes" if flag else "no")