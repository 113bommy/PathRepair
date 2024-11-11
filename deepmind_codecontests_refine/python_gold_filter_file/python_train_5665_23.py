n = int(input())
upper = []
lower = []
a = -1
for i in range (n):
    x,y = map(int,input().split())
    upper.append(x)
    lower.append(y)
if sum(upper)%2 == 0 and sum(lower)%2 ==0:
    print(0)
elif (sum(upper)%2 == 0 and sum(lower)%2 ==1) or (sum(upper)%2 == 1 and sum(lower)%2 ==0):
    print(-1)
elif sum(upper)%2 == 1 and sum(lower)%2 ==1:
    for i in range (len(lower)):
        if (lower[i] % 2 == 0 and upper[i]%2 ==1) or (lower[i] % 2 == 1 and upper[i]%2 ==0):
            print(1)
            a = 1
            break
    
    if a == -1 :
        print(-1)
