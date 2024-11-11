def main():
    counts = [int(x) for x in input().split()]
    vlad_quantity, valera_quantity = counts[0], counts[1]
    counter = 1

    while True:
        if counter % 2 != 0:
            if vlad_quantity >= counter:
                vlad_quantity -= counter
            else:
                return 'Vladik'
        else:
            if valera_quantity >= counter:
                valera_quantity -= counter
            else:
                return 'Valera'
        counter += 1


if __name__ == '__main__':
    print(main())
