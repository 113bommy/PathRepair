i = int(input())
c = '8'*(i//2) + '6'*(i%2)
print(c if i<36 else -1)