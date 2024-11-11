n=int(input())
a = list(map(int, input().split()))
maximum=max(a)
minimum=min(a)
if minimum==maximum:
    print(0,n//2*(n-1))
else:
    print(maximum-minimum,a.count(maximum)*a.count(minimum))