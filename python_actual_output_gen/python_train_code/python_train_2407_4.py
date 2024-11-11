q,h,s,d=map(int,input().split())
N=int(input())
s=min(q*4,h*2,s)
print(min(s*N,d*(N//2)+a*(N%2)))