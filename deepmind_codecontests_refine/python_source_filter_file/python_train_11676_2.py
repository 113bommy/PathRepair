n=int(input())
count=0
while n>=10:
    rem=10-n%10
    n+=rem
    count+=rem
    if n%10==0:
        n//=10
print(count)