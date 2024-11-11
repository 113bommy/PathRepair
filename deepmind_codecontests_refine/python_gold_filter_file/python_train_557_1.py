n = int(input())

_sum = 0
string = ""
for i in range(n):
    A,G = [int(i) for i in input().split(" ")]
    if (abs(_sum + A) <= 500):
        _sum += A
        string += "A"
    else:
        _sum -= G
        string += "G"
    

print(string)
