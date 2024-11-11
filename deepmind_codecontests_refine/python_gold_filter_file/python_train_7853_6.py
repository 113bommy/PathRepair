a=int(input())
b=sorted(list(map(int,input().split())))
b_max=max(b)
b_min=min(b)
print(b_max-b_min,end=" ")
if b_max!=b_min:
    print(b.count(b_max)*b.count(b_min))
else:
    print(b.count(b_max)*(b.count(b_max)-1)//2)
