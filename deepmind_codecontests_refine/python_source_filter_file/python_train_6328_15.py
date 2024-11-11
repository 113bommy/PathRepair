N = int(input())
arr = [0]*100
for num in range(1,N):
  arr[int(str(num)[0]+str(num)[-1])] += 1
print(sum([arr[i*10+j]*arr[j*10+i]  for i in range(10) for j in range(10)]))