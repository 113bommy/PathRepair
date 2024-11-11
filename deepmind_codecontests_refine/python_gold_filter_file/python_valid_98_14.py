def st(s):
    flag = 0
    for i in range(0,len(s)-1):
        if s[i] !=s[i+1]:
            print(i+1,i+2)
            flag = 1
            break
    if flag==0:
        print(-1,-1)
    
t = int(input())
for i in range(0,t):
    n = input()
    s = input()
    st(s)