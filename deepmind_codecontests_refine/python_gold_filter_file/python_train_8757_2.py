n = int(input()) # len(array)
array = list(map(int, input().split()))# [2, 1, 4, 2, 3, 4, 5,]

# do the countdict
countdict = {}
for i in range(n):
        countdict[array[i]] = i



max = -1 #(maxindex)
count = 0 #(free) 
for i in range(n):
    if i > max and countdict[array[i]] == 1:
        count += 1
    elif i > max:
        count += 1
    if  max < countdict[array[i]]:
        max = countdict[array[i]] 
print((2**(count-1) % 998244353))
