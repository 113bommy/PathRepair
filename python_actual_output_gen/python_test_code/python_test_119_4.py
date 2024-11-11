n ,t = map(int, input().split())
mini = 1
mint = 10 ** 9 + 1
for i in range(n):
    s, d = map(int, input().split())

    if s >= t:
        time = s 
    else:
        y = (t - s + d -1)/d
        time = s + y * d
        

    if time < mint:
        mint = s
        mini = i + 1


print(mini)

    
    

