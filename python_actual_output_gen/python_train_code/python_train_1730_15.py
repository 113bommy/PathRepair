n = int(input())
arr = []
for i in range(n):
   input_arr = input().split()
   arr.append(input_arr)

for i in range(len(arr)):
   for j in range(len(arr[i])):
      arr[i][j] = int(arr[i][j])
#print(arr[0][0])   
for i in range(len(arr)):
   
   count = 0
   now_vol = arr[i][0]
   want_vol = arr[i][1]
   #print(now_vol,want_vol)
   volume = abs(now_vol - want_vol)
   #print(volume)
   if volume > 5:
      count += volume // 5
      volume = volume % 5
   #print(volume)
   if volume > 2:
      count += volume // 2
      volume = volume % 2
   #print(volume)
   if volume == 1:
      count += 1
   print(count)
