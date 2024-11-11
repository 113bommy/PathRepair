def main():
    t=int(input())
    for _ in range(t):
        l=list(map(int,input().split()))
        l=sorted(l)
        if l[2]>l[1]+l[0]:
            print('no')
        else:
            print('yes')
        
if __name__=="__main__":
    main()
