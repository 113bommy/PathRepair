n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
print( sum( a[(i+1)//2] for i in range(n)) )