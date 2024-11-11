n_k  = [int(i) for i in input().split()]

problems = n_k[0]

if n_k[1] == 240:
    print("0")
else:
    while(problems):
        if(5*problems*(problems+1)/2) + n_k[1] <= 240:
            print(problems)
            break
        else:
            problems-=1
        
