n=int(input())
s=sorted([int(input()) for _ in range(n)])
sum_s=sum(s)
if sum_s%10!=0:
    print(sum_s)
else:
    for i in s:
        if i %10!=0:
            print(sum_s-i)
            exit()
print(0)
