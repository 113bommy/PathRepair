a = int(input())
b = int(input())
arr1 = [i+1 for i in range(a+1)]
arr2 = [j+1 for j in reversed(range(b))]
arr = arr1+arr2
print(" ".join(map(str,arr)))