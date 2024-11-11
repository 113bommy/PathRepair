x = int(input())
l = [i**j for i in range(1,33) for j in range(2,10) if i**j <= x]
print(l[-1])