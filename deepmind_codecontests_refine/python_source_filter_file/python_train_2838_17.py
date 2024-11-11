t = int(input())
while(t):
    t -=1
    num = list(map(int,input().split(" ")))
    num.sort()
    if(num[1] !=num[2]):
        print("NO")
    else:
        print("YES")
        print(num[1]," ",num[1]," ",num[2])

