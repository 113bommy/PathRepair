for _ in range(int(input())):
    name, before, after = input().split()
    if int(before) >=2400:
        if int(after) > int(before):
            #print(name)
            print("YES")
            exit(0)
print('NO')
