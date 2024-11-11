# print ("Input number of cars")
n = int(input())

# print ("Input all the service times")
therow = input().split()
therow = [int(i) for i in therow]
therow.sort()

answer = 0
waittimetohere = 0
for i in therow:
    if waittimetohere <= i:
        answer = answer + 1
        waittimetohere = waittimetohere + i
print (answer)
    
