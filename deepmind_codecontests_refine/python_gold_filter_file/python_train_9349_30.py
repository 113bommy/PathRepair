k, a, b = map(int, input().split())
if 2 >= b - a or k+1 <= a:
    print(k+1)
else:
    i = -(a-k-1)//2
    ans = k+1 -a*i + b*i -2*i
    print(ans)