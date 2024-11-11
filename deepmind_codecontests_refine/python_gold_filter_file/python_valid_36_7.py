for _ in range(int(input())):
    n = int(input())
    ans = ''
    if n%2==1:
        ans+='c'
        n-=1
    ans+='a'*(n//2)
    ans+='b'
    ans+='a'*(n//2-1)
    if n==0:
        print("a")
        continue
    print(ans)