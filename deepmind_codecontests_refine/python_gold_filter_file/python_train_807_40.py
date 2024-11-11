def main():
    n=int(input())
    d=[0]+[-10**18]*n
    for j,(a,i)in enumerate(sorted((-a,i)for i,a in enumerate(map(int,input().split())))):
        d=[max(t-a*abs(~i-j+k+n),d[k-1]-a*abs(~i+k))for k,t in enumerate(d)]
    print(max(d))
main()