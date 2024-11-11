k,a,b = map(int,input().split())
if a+2 > b:
    print(k+1)
else:
    print(a-1 + (b-a)*(k-a+1)//2 + (k-a+1)%2)