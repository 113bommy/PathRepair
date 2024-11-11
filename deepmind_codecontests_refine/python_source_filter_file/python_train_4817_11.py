for _ in range(int(input())):
    total = int(input())
    num_l = list(map(int,input().split()))
    num_l.sort()
    num_l.reverse()
    if total == 1:
        print('T')
    elif total == 2:
        if num_l[0] == num_l[1]:
            print('HL')
        else:
            print('T')
    else:
        zero = 0
        while True:
            print(num_l)
            while num_l[1] >= num_l[2] and num_l[1] != 0:
                num_l[0] -= 1
                num_l[1] -= 1
            if num_l[1] == 0:
                zero += 1
            for count in range(1,total-1):
                if num_l[count] < num_l[count+1]:
                    (num_l[count],num_l[count+1]) = (num_l[count+1],num_l[count])
                else:
                    break
            if num_l[0] == 0:
                zero += 1
            for count in range(0,total-1):
                if num_l[count] < num_l[count+1]:
                    (num_l[count],num_l[count+1]) = (num_l[count+1],num_l[count])
                else:
                    break
            if zero == total:
                print('HT')
                break
            elif zero == total-1:
                print('T')
                break
