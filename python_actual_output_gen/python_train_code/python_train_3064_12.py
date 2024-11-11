v = [8,2,5,5,4,5,6,3,7,6]
p = input()
p = p.split(' ')
answer = 0
for k in range(int(p[0]),int(p[1])+1,1):
    for q in str(k):
        answer += int(v[int(q)])
print(answer)
