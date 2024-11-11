k = int(input())
a,b = map(int, input().split)
largest = (b//k)*k
print("OK" if largest >= a else "NG")