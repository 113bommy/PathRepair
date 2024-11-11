n = int(input())
li = [int(i) for i in input().split()]
sum = 0
for i in li:
    sum+=i/100
print((sum/n)*100.00)