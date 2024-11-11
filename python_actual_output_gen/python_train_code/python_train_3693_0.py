n=input()
for j in range(len(n)-1,-1,-1):
    num=int(n[j])
    if(num>=5):
        print("-0|",end="")
        num=num-5
    else:
        print("0-|",end="")
    for _ in range(num):
        print("0",end="")
    print("-",end="")
    for k in range(4-num):
        print("0",end="")
    print("")
    