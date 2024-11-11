n, w, b = map(int, input().split())
values = list(map(int, input().split()))

i = 0
j = n - 1
cost = 0
while i <= j:
    #print(cost, values[i], values[j])
    if values[i] == values[j] == 0 or values[i] == values[j] == 1:
        pass
    elif values[i] == values[j] == 2 and i != j:
        cost += 2 * min(w , b)
    elif values[i] == values[j] == 2 and i == j:
        cost += min(w , b)
    elif values[i] != values[j] and values[j] == 2:
        if values[i] == 0:
            cost += w
        else:
            cost += b
    elif values[i] != values[j] and values[i] == 2:
        if values[j] == 0:
            cost += w
        else:
            cost += b
    elif values[i] != values[j] and (values[i] != 2 and values[j] != 2) :
        cost = -1
        break
    i += 1
    j -= 1

print(cost)