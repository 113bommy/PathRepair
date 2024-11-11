for t in range(int(input())):
    N=int(input())
    K=N//4
    if(N==1):
        print('8')
    elif(N==2):
        print('98')
    elif(N==3):
        print('998')
    elif(N==4):
        print('9998')
    else:
        print('(N-K-1)*9'+'(K+1)*8')