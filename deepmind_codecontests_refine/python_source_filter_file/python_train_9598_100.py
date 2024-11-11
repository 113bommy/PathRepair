def main():
    n,a,b=map(int,input().split())
    print(max(a+1,n-b))
if __name__=='__main__':
    main()