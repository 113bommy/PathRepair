#codeforces
if __name__=='__main__':
    for _ in range(int(input())):
        a,b,c,n=map(int,input().split())
        m=max(a,b,c)
        s=(m-a)+(m-b)+(m-c)
        r=n-s
        if r>=0 and r%3==0:
            print("YES")
        else:
            print("NO")