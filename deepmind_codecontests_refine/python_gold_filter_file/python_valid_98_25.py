for _ in range(int(input())):
    n = int(input())
    s = input()
    l = 0
    r = n-1
    count_a = s.count('a')
    count_b = s.count('b')
    flag = False
    while r>l :
        if count_a == count_b :
            print(l+1, r+1)
            flag = True
            break

        elif count_a > count_b :
            if s[l] == 'a' :
                l += 1
                count_a -= 1
            elif s[r] == 'a' :
                r -= 1
                count_a -= 1
            else :
                l += 1
                count_b -= 1

        elif count_b > count_a :
            if s[l] == 'b' :
                l += 1
                count_b -= 1
            elif s[r] == 'b' :
                r -= 1
                count_b -= 1
            else :
                l += 1
                count_a -= 1
    if not flag :
        print(-1,-1)