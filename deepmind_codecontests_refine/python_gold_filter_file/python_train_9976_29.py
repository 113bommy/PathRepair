x = int(input())
print(max([i**ii for i in range(1,34) for ii in range(2,11) if i**ii <= x]))