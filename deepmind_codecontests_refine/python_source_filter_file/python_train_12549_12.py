l = input().split()
btns = list(map(int, input().split()))
count = 0
if(len(btns)==1):
    if(int(btns[0])== 1):
        print("YES")
    else:
        print("NO")
else:
    for button in btns:
        if(button==0):
            count = count + 1
        if(count>=2):
            break
    if(count>=2 and count==0):
        print("NO")
    else:
        print("YES")