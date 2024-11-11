def main():
    n,a,b=map(int,input().split())
    print(n-max(a+1,n-b)+1)
if __name__=='__main__':
    main()