n = int(input())
l = list(map(int,input().split()))
ans1 = 0
ans = 0
if l[0] > 15:
    print(15)
elif l[0] <= 15 and n == 1:
    print(l[0]+15)
else:
    for i in range(len(l)-1):
        if abs(l[i]-l[i+1]) > 15:
            print(l[i]+15)
            exit()
        else:
            ans = l[i+1]
            ans1 += 1
    if ans > 75:
        print(90)
    else:
        print(ans+15)
