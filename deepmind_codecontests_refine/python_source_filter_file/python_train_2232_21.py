a1,a2,a3,a4=map(int,input().split())
nums=input()
counter=0
num=list(nums)
for i in num:
    if int(i)==a1:
        counter+=a1
    if int(i)==a2:
        counter+=a2
    if int(i)==a3:
        counter+=a3
    if int(i)==a4:
        counter+=a4
print(counter)
    