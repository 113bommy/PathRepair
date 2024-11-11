if __name__=="__main__":
    for _ in range(int(input())):
        n=int(input())
        a=list(map(int,input().split()))
        a.sort(reverse=True)
        ne=0
        for i in range(n):
            if a[i]<0:
                ne=ne+1
        m1=a[0]*a[1]*a[2]*a[3]*a[4]
        m2=a[0]*a[1]*a[2]*a[-1]*a[-2]
        m3=a[0]*a[-1]*a[-2]*a[-3]*a[-4]
        if ne<4 and ne>=2:
            print(max(m1,m2))
        elif ne>=4 and n!=ne:
            print(max(m1,m2,m3))
        else:
            print(m1)


