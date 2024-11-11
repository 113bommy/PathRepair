n=int(input())
num=n
for i in range(5):
    n=num+i
    val=n
    num_sum=0
    while n>0:
        num_sum=num_sum+n%10
        n=n//10
    if num_sum%4==0:
        print(val)
        break