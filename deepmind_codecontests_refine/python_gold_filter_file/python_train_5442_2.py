# cook your dish here
for t in range(int(input())):
    n = int(input())
    s = input()
    if n&1:
        f = 2 
        for i in range(0,len(s),2):
            if int(s[i])&1:
                f=1
                break
    else:
        f=1
        for i in range(1,len(s),2):
            if int(s[i])%2==0:
                f=2
                break
    print(f)    
        