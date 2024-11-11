def main():
    n,m=map(int,input().split())
    max_rem= n-m+1
    maxi = (max_rem)*(max_rem-1)//2
    if(n%m==0):
        x=n//m
        pmin=(int)((x*(x-1))/2)*m
    else:
        x=(n//m)
        pmin=((x*(x-1))/2)*(m-(n%m))
        pmin+=(((x+1)*x)/2)*(n%m)
    print(pmin,maxi)
main()