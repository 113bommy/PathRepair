n = int(input())
light = input().split()
light = list(map(int,light))

count =0
for i in range(0,n):
    if light[i:i+3]==[1,0,1] and i+3<n:
        light[1+3] = 0
        count+=1
    # print(light[i:i+3])
print(count)
