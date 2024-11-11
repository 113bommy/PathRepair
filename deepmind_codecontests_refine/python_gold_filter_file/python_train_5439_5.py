tc = int(input())
for _ in range(tc):
    n = int(input())
    ans = []
    # re =0
    # while n>0:
    #     d = n % 10
    #     re = re*10 + d
    #     print(re)
    #     n = n//10

    n = str(n)
    n = n[::-1]
    if len(n) == 1:
        print(1)
        print(n)
    else:
        for i in range(0,len(n)):
            if n[i] !='0':
                ans.append(str(int(n[i])*(10**(i))))

        print(len(ans))
        print(" ".join(ans))