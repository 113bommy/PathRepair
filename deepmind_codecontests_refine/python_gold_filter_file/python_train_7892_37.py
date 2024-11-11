li = list(map(int,input().split()))
n=int(input())
print(max(li)*(2**n-1)+sum(li))