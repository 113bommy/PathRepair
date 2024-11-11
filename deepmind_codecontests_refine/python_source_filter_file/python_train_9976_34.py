x = int(input())
print(max(i ** j for i in range(2, 34) for j in range(2, 11) if i ** j <= x))