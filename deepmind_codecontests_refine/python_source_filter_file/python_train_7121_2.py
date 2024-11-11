n=int(input())
a=list(map(int,input().split()))
count_5=a.count(5)//9
count_0=a.count(0)
if count_0<=0:
    print(0)

else:
    print(int('5'*(count_5*9)+'0'*count_0))


