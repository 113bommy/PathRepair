n,b,d = map(int, input().split())
oranges = list(map(int, input().split()))
# oranges = [ orange for orange in oranges if orange < b ]
overflows = 0 
theSum = 0 
for orange in oranges:
    if orange < b:
        theSum += orange
        if theSum > d:
            overflows += 1
            theSum  = 0

# while (sum(oranges) > d ):
#     overflows +=1

print(overflows)