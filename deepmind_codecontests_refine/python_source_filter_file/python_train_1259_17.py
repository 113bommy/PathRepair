for _ in range(int(input())):
    n  =int(input())
    s = input()
    ans = "YES"
    for i in range(n//2):
        if(abs(ord(s[i])-ord(s[n-i-1]))>2 and abs(ord(s[i])-ord(s[n-i-1]))!=1):
            ans = "NO"
            break
    print(ans)