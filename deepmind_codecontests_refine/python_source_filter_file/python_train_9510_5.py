def main():
    number_of_cities = int(input())
    cities = [int(x) for x in input().split()]
    lowest_number = cities[0]
    index = 0
    bad = 0
    for i in range(len(cities)):
        if cities[i] < lowest_number:
            lowest_number = cities[i]
            index = i+1
    for i in range(number_of_cities):
        if cities[i] == lowest_number:
            bad += 1
    if bad >= 2:
        print("Still Rozdil")
    else:
        print(index)


main()
