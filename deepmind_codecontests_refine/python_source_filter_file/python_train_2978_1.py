def  sum_of_its_digits(Num, s):
    S=str(Num)
    sum=0
    for i in S:
        sum+=int(i)
    return (Num-sum)>=s


k=input().split()
n=int(k[0])
s=int(k[1])
for i in range(1, n+1):
    if(sum_of_its_digits(i, s)):
        sum=n-i+1
        break
print(sum)
