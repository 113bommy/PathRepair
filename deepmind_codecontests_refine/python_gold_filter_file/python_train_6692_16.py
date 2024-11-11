n = int(input())
for _ in range(0,n):
    x = input()
    l = len(x)
    if(l==4):
        press = 10*(int(x[0]))
    else:
        press = 10*(int(x[0])-1) + l*(l+1)/2
    print(int(press))