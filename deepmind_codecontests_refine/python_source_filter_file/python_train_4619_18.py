n = int(input(''))
prob_list = []
for x in range(n):
    ip = input('')
    prob_list.append(ip)
    
op = 0
for x in prob_list:
    count = 0
    for i in x.split(' '):
        if i == '1':
            count += 1
    if count>=2:
        op += 1
op