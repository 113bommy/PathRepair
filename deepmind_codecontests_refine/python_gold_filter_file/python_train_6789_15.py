for i in range(int(input())):
    A,B= map(int,input().split())
    print(A*(len(str(B+1))-1))