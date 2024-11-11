def func():
    global x
    if x % 2 == 0:
        print(x // 2)
    else:
        count = 0
        for i in range(3, int((x+1)**(1/2)), 2):
            if x % i == 0:
                x -= i
                count += 1
                break
        else:
            print(1)
            return

        print(count + x // 2)


x = int(input())
func()
