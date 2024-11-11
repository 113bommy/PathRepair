t= int(input())
for _ in range(t):
    n = int(input())
    i =1
    c = 0
    temp = []
    while n:
        # print("n: ", n)
        r =n%10
        # print("r: ", r)

        if r >0:
            c+=1
            temp.append((r*10**(i-1)) )
            # print(temp)
        n = n//(10)
        # print("new_n: ", n)

        i+=1
    print(c)
    for k in temp:
        print(k, end=" ")
    print()