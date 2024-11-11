def main():
    n = int(input())
    a = list(map(int,input().split()))
    c = 1
    ans = 0
    a.sort()
    p1 = 0
    p2 = 1
    l = 1
    while(p1<=p2 and p2<len(a)):
        if a[p2]-a[p1] <= 5:
            l = max(p2-p1+1,l)
            p2+=1
        else:
            p1+=1
    print(l)
main()