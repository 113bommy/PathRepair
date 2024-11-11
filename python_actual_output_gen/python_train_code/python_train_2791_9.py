n=int(input())
for i in range(n):
    k,x=map(int,input().split())
    print(9*(k-1)+x%9)
    
