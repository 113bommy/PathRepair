def main():
    T=int(input())
    for _ in range(T):
        N,M=map(int,input().split())
        if N%M==0:
            print("YES")
        else:
            print("NO")
if __name__=='__main__':
    main()