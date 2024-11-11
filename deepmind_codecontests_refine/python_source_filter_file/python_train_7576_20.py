n=int(input())
list1=list(map(int,input().split()))
import fractions
ans=list1[0]
for i in range(1, n):
    ans = ans * list1[i] // fractions.gcd(ans, list1[i])
sum1=0
for i in list1:
    sum1+=ans//i
print(sum1//(10**9+7))