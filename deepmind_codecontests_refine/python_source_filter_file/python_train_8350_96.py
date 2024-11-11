for i in range(int(input())):
    (h,m)=map(int,input().split())
    rem = (60-m)+(24-h)*60
    print(rem)