n = int(input())
a = list(map(int,input().split()))
a = sorted(a)
if(n%2!=0) :
    print(a[int(n/2)])
else :
    print(a[int((n+1)/2)])