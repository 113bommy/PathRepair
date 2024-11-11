n,a,x,b,y = list(map(int,input().split()))

flag = False
while a != x%n and b != y%n:
    a = (a+1)%n 
    b = (b-1)%n 
    #print(a,b)
    if a == b:
        flag =  True
        break
if flag:
    print("YES")
else:
    print("NO")