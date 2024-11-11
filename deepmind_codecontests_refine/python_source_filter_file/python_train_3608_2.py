n=int(input())
a=list(map(int,input().split()))
sum1=int(sum(a)/2)
sum2=0
for i in range(len(a)):
    sum2+=a[i]
    if sum2>=sum1:
        print(i+1)
        break;