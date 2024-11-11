def main():
    X,Y=map(int,input().split())
    ans=0
    for x in range(1,min(X,Y)+1):
        ans+=((x+Y)//5)-(x//5)
    print(ans)
if __name__=='__main__':
    main()