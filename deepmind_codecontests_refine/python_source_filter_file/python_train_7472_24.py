def main():
    n = int(input())
    S = [input() for _ in [0]*n]
    s2 = []
    s3 = []
    for s in S:
        temp = [0, 0]
        m = 0
        now = 0
        for i in s:
            if i == "(":
                now += 1
            else:
                now -= 1
            m = min(m, now)
        temp[0] = -m
        temp[1] = (s.count("(")-s.count(")"))-m
        if temp[0] < temp[1]:
            s2.append(temp)
        else:
            s3.append(temp)
    s2.sort(key=lambda x: (x[0]))
    s3.sort(key=lambda x: (-x[1]))
    cnt = 0
    for i, j in s2:
        cnt -= i
        if cnt < 0:
            print("No")
            return
        cnt += j
    for i, j in s3:
        cnt -= i
        if cnt < 0:
            print("No")
            return
        cnt += j
    if cnt != 0:
        print("No")
        return
    print("Yes")


main()
