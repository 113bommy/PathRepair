def main():
    N=input()
    if len(N)==1 and N[0]=='1':
        print(4)
    else:
        if len(N)==1:
            nMod4=int(N)%4
        else:
            nMod4=int(N[-2::])%4
        nMod2=int(N[-1])%2
        print(((1%5)+([2,4,8,6][nMod4-1]%5)+([3,9,7,1][nMod4-1]%5)+([4,6][nMod2-1]%5))%5)
if __name__=='__main__':
    main()