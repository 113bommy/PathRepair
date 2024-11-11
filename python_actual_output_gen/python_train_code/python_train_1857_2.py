a = int(input())
b = int(input())
arr1 = [2*i for i in range(1,a+2)]
arr2 = [2*j+1 for j in reversed(range(b))]
arr = arr1+arr2
print(" ".join(map(str,arr)))