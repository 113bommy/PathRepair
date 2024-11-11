l,r= map(int,input().split())
num = r-l

if num == 1 :
    print("-1")

elif num == 2 :
    if l %2 !=0:
        print("-1")
    else:
         print(l, l + 1, l + 2)

elif num > 2:
    if l % 2 == 0 :
        print(l,l+1,l+2)
    else:
        print(l+1,l+2,l+3)
