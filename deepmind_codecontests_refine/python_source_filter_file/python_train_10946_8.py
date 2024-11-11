line = input().split(' ')
f = int(line[0])
r = int(line[1])
c = int(line[2])

w1 = int(f/3)
w2 = int(r/2)
w3 = int(c/2)
ans = 0

fr = {'00': 1, '01' : 2, '10': 3, '11' : 4, '20' : 3, '21' : 5}
fc = {'00': 1, '01' : 2, '10': 2, '11' : 3, '20' : 4, '21' : 5}
rc = {'00': 2, '01' : 2, '10': 3, '11' : 5}
frc = {'000': 0, '001' : 1, '010': 1, '011' : 2, '100': 1, '101' : 2, '110': 2, '111' : 3, '200': 2, '201' : 2, '210': 3, '211' : 4}

if w1 < w2 and w1 < w3:
    re = f % 3
    if re == 0:
        ans = w1 * 7 + 2
    elif re == 1:
        ans = w1 * 7 + 3
    elif re == 2:
        ans = w1 * 7 + 6

elif w2 < w1 and w2 < w3:
    re = r % 2
    if re == 0:
        ans = w2 * 7 + 3
    elif re == 1:
        ans = w2 * 7 + 6
        
elif w3 < w1 and w3 < w2:
    re = c % 2
    if re == 0:
        ans = w3 * 7 + 4
    elif re == 1:
        ans = w3 * 7 + 6
        
elif w1 == w2 and w1 < w3:
    re1 = f % 3
    re2 = r % 2
    
    feature = str(re1) + str(re2)
    ans = w1 * 7 + fr[feature]

elif w1 == w3 and w1 < w2:
    re1 = f % 3
    re3 = c % 2
    
    feature = str(re1) + str(re3)
    ans = w1 * 7 + fc[feature]
    
elif w2 == w3 and w2 < w1:
    re2 = r % 2
    re3 = c % 2
    
    feature = str(re2) + str(re3)
    ans = w2 * 7 + rc[feature]
    
else:
    re1 = f % 3
    re2 = r % 2
    re3 = c % 2
    
    feature = str(re1) + str(re2) + str(re3)
    ans = w1 * 7 + frc[feature]
    # print(feature)
    
print(ans)
