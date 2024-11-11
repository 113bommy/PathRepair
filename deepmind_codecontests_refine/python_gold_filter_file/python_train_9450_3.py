def f():
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    now=1

    for i in range(k.bit_length()):
        if k and k%2:now=l[now-1]
        l=tuple(l[l[i]-1]for i in range(n))
        k//=2
    print(now)
if __name__ == "__main__":
    f()