for x in range(int(input())):
    a=list(map(int,input().split()))
    hh=a[0]
    mm=a[-1]
    print(((23-hh)*60)+(60-mm))