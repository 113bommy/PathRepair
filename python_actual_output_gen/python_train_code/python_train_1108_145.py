print ("Input small and large bear weights")
a,b = [int(x) for x in input().split()]

answer = 0
while a <= b:
    a *= 3
    b *= 2
    answer += 1
print(answer)
