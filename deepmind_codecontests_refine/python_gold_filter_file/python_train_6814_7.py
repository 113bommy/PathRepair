n = int(input())
exp=19;
sum = (10 ** (exp-1)) * exp * 45
sum+=1

l=1
r=(10**19)

dif=n-(sum%n)
l+=dif
r+=dif

print(l,r)
