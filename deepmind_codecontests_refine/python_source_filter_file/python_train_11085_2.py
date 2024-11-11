n=int(input())
arr = [int(i) for i in input().split()]
min=arr.count(2)+arr.count(3)
if min>(arr.count(1)+arr.count(3)):
    min=arr.count(1)+arr.count(3)
elif min>(arr.count(1)+arr.count(2)):
    min=(arr.count(1)+arr.count(2))
print(min)
    

