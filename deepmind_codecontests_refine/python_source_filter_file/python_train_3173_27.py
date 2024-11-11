def main():
    n,k= map(int,input().split())
    arr = list(map(int,input().split()))
    if max(arr)-min(arr)>k:
        print("NO")
    else:
        print("YES")
        l=[]
        for i in range(k):
            l.append(i+1)
        p=[k]*1000
        l+=p
        for x in arr:
            print(*l[:x])
if __name__ == '__main__':
    main()