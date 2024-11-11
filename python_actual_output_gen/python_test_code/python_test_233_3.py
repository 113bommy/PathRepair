a, b=map(int, input().split(' '))
ints=list(map(int, input().split(' ')))
ints.sort()

dictionary={}

for num in ints:
    if (num/b)%1!=0:
        dictionary[num] = 1
    else:
        if int(num/b) in dictionary:
            dictionary[num]=1

print(len(dictionary))
