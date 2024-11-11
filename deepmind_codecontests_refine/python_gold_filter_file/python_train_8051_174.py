n = int(input())
fornow = 0
drinks = map(int,input().split())
for i in drinks:
    fornow += i/100
print(fornow/n*100)