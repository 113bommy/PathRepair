n = int(input())
array = list(map(int, input().split()))

i = 0
j = len(array) - 1

s1 = array[i]
s3 = array[j]

result = []

while(i <= j):
    
    if (s1 < s3):
        i += 1
        s1 += array[i]
    elif (s1 > s3):
        j -= 1
        s3 += array[j]
    else:
        result.append(s1)
        i += 1
        j -= 1
        s1 += array[i]
        s3 += array[j]

if (len(result) == 0):
    print(0)
else:
    print(max(result))

