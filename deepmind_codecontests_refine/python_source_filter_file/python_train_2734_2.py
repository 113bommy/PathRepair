def game():
    list1 = []
    output_list = []
    a = input()
    for i in range(2*int(a)):
        a = input()
        if i % 2 != 0:
            listr = sorted([int(j) for j in a.split(" ")])
            list1.append(listr)
    for i in list1:
        count = 0
        init_var = i[0]
        for j in i:
            if j - init_var > 1:
                output_list.append("NO")
                break
            count += 1
            init_var = j
        if count == len(i):
            output_list.append("YES")
    print("\n".join(output_list))
