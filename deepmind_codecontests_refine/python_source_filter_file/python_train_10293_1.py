n=int(input())
A=list(map(int,input().split()))
m=sum(A)//n
print(max(sum(map(lambda x:(x-m)**2,A)),sum(map(lambda x:(x-m-1)**2,A)))