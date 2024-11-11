a = input()
b = input()
arr = [0] * 5
brr = [0] * 5
i = -1
for char in a:
    i += 1
    arr[i] = char
i = -1
for char in b:
    i += 1
    brr[i] = char
c = (int(arr[0] + arr[1]) + int(brr[0] + brr[1]))//2
g = (int(arr[3] + arr[4]) + int(brr[3] + brr[4]))/2
if (int(arr[0] + arr[1]) + int(brr[0] + brr[1]))%2 > 0:
    g += 30
if g > 60:
    c += 1
    g -= 60
g = int(g)
if c < 10:
    c = str(0) + str(c)
if g < 10:
    g = str(0) + str(g)
print(c,":",g,sep ='')
