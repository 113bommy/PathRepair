n = int(input())
above = [int(x) for x in input().split()]
below = [int(x) for x in input().split()]
taken_above = [above[0]]
taken_below = [below[0]]
taken_none = [0]
for i in range(1,n):
    taken_above.append(max(taken_below[i-1]+above[i],taken_none[i-1]+above[i]))
    taken_below.append(max(taken_above[i-1]+below[i],taken_none[i-1]+below[i]))
    taken_none.append(max(taken_none[i-1],taken_below[i-1],taken_above[i-1]))
    
print(max(taken_above[n-1],taken_below[n-1],taken_none[n-1]))