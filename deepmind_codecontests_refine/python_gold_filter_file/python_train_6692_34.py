t=int(input())
sum=0
while t>0:
    n=int(input())
    str_n=str(n)
    length,first=len(str_n),n%10
    sum=(first-1)*10
    sum+=(length*(length+1))//2
    print(sum)
    t-=1
    