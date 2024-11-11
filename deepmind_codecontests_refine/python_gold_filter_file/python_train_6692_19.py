t = int(input())
while t != 0:
    t-=1
    s = str(input())
    n = int(s[0])
    ans = (n-1)*10
    lens = len(s)
    ans += lens*(lens+1)/2
    print(int(ans))
    
