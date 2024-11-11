n = int(input())
print(*[[9,n-9],[8,n-9]][not n&1])
