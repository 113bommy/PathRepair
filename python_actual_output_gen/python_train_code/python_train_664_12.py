n = int(input())
lis=list(map(int,input().split()))
for i in lis:
    a=i%14
    if a>0 and a<=6 and n>=14:
        print("YES")
    else:
        print("NO")    

