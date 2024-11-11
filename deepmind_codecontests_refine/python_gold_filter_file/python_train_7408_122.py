#n,m,k = map(int,input().split())
#stu = list(map(int,input().split()))
#sch = list(map(int,input().split()))
#ids = list(map(int,input().split()))
n = int(input())
if n%2==0:
    print(2**(n//2))
else:
    print(0)
