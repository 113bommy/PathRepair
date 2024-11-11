import sys
def main():
    for _ in range(int(sys.stdin.readline())):
        n,d = map(int,sys.stdin.readline().split())
        l=[int(y) for y in sys.stdin.readline().split()]
        ans=l[0]
        flag=0
        for i in range(1,n):
            x=l[i]*i
            if x>d:
                flag=1
                #ans += d // i
                break
            else:
                ans+=l[i]
                d=d-x
        #print(ans)
        if flag==1:
            for j in range(l[i]):
                d=d-i
                if d>=0:
                    ans+=1
                else:
                    break
        print(ans)

if __name__ == "__main__":
    main()