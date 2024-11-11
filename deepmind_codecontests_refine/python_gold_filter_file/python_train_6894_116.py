for i in range(int(input())):
    a,b=map(int,input().split())
    if a%b==0:
        print('yes'.upper())
    else:
        print('no'.upper())