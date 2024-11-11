for _ in range(int(input())):
    l = []
    for _ in range(int(input())):
        l.append(int(input()))

    count = 0
    kurcic = set()
    for kita in l:
        kurcic.add(kita%10)

    for i in range(len(l)):
        for j in range(len(l)):
            if i == j:
                continue
            if l[i] == l[j]:
                l[i] = l[i] // 10
                l[i] = l[i] * 10
                for picic in range(0, 9):
                    if picic not in kurcic:
                        l[i] = l[i] + picic
                        kurcic.add(picic)
                        break
                count += 1
                break

    print(count)
    for ele in l:
        print(f"{ele:04d}")
