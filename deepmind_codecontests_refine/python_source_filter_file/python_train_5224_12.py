def fill_hotel_num(hotel, rng):
    for x in rng:
        if hotel[x] == '0':
            hotel[x] = '1'
            return

def op(hotel, symbol):
    if symbol.isdigit():
        hotel[int(symbol)] = '0'
    elif symbol == 'R':
        fill_hotel_num(hotel, range(9, 0, -1))
    else:
        fill_hotel_num(hotel, range(10))
    return hotel

if __name__ == '__main__':
    str_len = int(input())
    ops = input()
    hotel = ['0' for x in range(10)]
    for x in range(str_len):
        hotel = op(hotel, ops[x])
    print(''.join(hotel))