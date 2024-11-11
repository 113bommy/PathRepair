
def main():
    n = int(input())
    home = input()
    home_list = []
    table = {}

    for x in range(n):
        buff = input().split('->')
        tfr, tto = buff[0], buff[1]
        if tfr == home:
            home_list.append(tto)
        else:
            if tfr in table.keys():
                table[tfr] += 1
            else:
                table[tfr] = 1

    result = 'home'
    for x in home_list:
        if not x in table.keys() or table[x] == 0:
            result = 'contest'
            break
        else:
            table[x] -= 1

    print(result)



if __name__ == '__main__':
    main()
