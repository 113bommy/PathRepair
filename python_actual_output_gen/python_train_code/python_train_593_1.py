t = int(input())
for i in range(0,t):
    s=input().split()
    Tot =int(s[0])//int(s[1])
    LeftLen=int (s[2])//int(s[1])
    RightLen=int(s[3])//int(s[1])
    Ans=Tot+LeftLen-RightLen
    print(Ans-1)