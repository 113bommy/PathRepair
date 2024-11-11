if __name__=='__main__':
    d = (int)(input())
    n = (int)(input())
    a = list(map(int,input().split()))
    t = 0
    for i in range(1,len(a)):
        t+=d-a[i]
    print(t)