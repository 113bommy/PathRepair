def judge(a):
    while a%3!=0 or a>=7 :
        a=a-7
    if a%3==0 :
        print("YES")
    else :
        print("NO")
for i in range(0,int(input()),1):
    x=int(input())
    judge(x)
