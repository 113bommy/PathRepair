n=int(input())
arr=[int(x) for x in input().split()]
positive,negative,zero=0,0,0
for ele in arr:
    if ele >0:
        positive+=1
    elif ele<0:
        negative+=1
    else:
        zero+=1
half=(n//2)+1
if positive>=half:
    print(1)
elif negative>=half:
    print(-1)
else:
    print(0)