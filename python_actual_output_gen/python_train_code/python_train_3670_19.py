arr=str(input()).split()
num, count=int(arr[0]), int(arr[1])
for i in range(count):
    if num%10==0:
        num/=10
    else:
        num-=1
print(str(num)[:-2])