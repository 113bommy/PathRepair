n = int(input())
sum = 0
while (n >= 1 ):
    if n % 2 == 0 :
        n = n/2
    else :
        sum= sum + 1
        n = n / 2
print(sum)
