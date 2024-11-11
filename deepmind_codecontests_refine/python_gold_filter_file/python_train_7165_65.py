n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

sum1=0
sum2=0

for i,j in zip(a,b):
  if i>j:
    sum1+=(i-j)
  elif i<j:
    sum2+=(j-i)//2

print('Yes' if sum1<=sum2 else 'No')