n = int(input())
a = int(input())
n = n % 500 - a
print(["No", "Yes"][a <= 0])