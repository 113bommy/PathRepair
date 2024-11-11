def cnt(n):
    sum=0
    while(n):
        sum+=(n%10)
        n//=10
    return sum
t=int(input())
count=0
for i in range(19,11000000,9):
    if(cnt(i)==10):
        count+=1
        if(count==t):
            print(i)
            break
