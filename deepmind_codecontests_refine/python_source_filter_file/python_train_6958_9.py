q,h,s,d = map(int,input().split())
N = int(input())
one = min(q*4,h*2,s)
print(min(one*N,d*(N//2)+one*(n%2)))
