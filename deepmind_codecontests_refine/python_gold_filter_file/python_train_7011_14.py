if __name__== "__main__":
    lst=(input()).split(" ")
    n=int(lst[0])
    m=int(lst[1])
    ans=0
    for i in range(n+1):
        for j in range(m+1):
            if (i*i+j==n) and (i+j*j==m):
                ans=ans+1
    print(ans)            