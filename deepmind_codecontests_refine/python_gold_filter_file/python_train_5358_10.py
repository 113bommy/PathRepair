a = int(input())
b = int(input())
arr1 = [i for i in range(b+1,a+b+2)]
arr2 = [j+1 for j in reversed(range(b))]
arr = arr1+arr2
print(" ".join(map(str,arr)))