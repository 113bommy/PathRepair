n = int(input().strip())
arr = [int(i) for i in input().strip().split(" ")]
a = arr.count(1)
b = arr.count(2)
if a > b:
    print(b + (b-a)//3)
else:
    print(a)