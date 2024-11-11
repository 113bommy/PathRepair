n,k=map(int,input().split())
n2=n//2+ n%2
i=1
if k >= n:
    print(0,0,n)
else:
    win,cer=(n//2)//(k+1),(n//2)//(k+1)*k
    print(win,cer,n-win-cer)
