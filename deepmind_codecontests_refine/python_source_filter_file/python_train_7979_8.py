n,m = input().split()
byte_array =input().split(" ")

tetris = []
n= int(n)
for i in range(0,n+1):
    tetris.append(0)

for i in byte_array:
    tetris[int(i)] +=1
minim = 999
for i in range(1,n+1):
    minim = min(tetris[i], minim)

print(minim)
