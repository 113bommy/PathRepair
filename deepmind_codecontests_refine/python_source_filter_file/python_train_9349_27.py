k,a,b = map(int,input().split())
if a+2 >= b or a+2 >= k+1:
    print(k+1)
else:
    k -= a-1
    print(a+ (b-a)*(k//2) + k%2)