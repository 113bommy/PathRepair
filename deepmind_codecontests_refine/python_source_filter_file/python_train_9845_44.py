def main():
    anton = 0
    danik = 0
    n = input()
    s = input()
    for i in s:
        if i == 'A':
            danik += 1
        elif i == 'D':
            anton += 1
    if anton > danik:
        print('Anton')
    elif danik > anton:
        print('Danik')
    else:
        print('Friendship')



if __name__ == '__main__':
    main()