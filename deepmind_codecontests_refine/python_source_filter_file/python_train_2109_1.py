test=int(input())
def solve():
    n=int(input())
    s=input()
    x=0;y=0;ok=0
    for i in range(n-1):
        if s[i]<=s[i+1]:
            ok=1
        else:
            ok=0
            break
    if ok==1:
        print(s)
        return
        
    for i in range(n):
        if s[i]=='0':
            x+=1
        else:
            break
    for i in range(n-1,-1,-1):
        if s[i]=='1':
            y+=1
        else:
            break
    s=""
    for i in range(x+1):
        s=s+"0"
    for i in range(y):
        s=s+"1"
    print(s)
while test:
    solve()
    test-=1