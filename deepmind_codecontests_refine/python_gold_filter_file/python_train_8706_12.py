k1, k2, k3 = input().strip().split()
k1, k2, k3 = int(k1), int(k2), int(k3)


answer = 'NO'
intervals = [k1, k2, k3]
if intervals.count(1) >= 1:
    answer = 'YES'
elif intervals.count(2) == 1:
    if intervals.count(4) == 2:
        answer = 'YES'
elif intervals.count(2) >= 2:
    answer = 'YES'
elif intervals.count(3) == 3:
    answer = 'YES'
    
print (answer)
