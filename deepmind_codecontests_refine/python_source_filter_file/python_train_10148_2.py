def main():
    n, m, k = map(int, input().split())
    icons = list(map(int, input().split()))
    icons_for_launch_positions = list(map(int, input().split()))
    # n = 10
    # m = 12
    # k = 3
    # icons = [6, 1, 2, 9, 3, 10, 8, 5, 7, 4]
    # icons_for_launch_positions = [3, 9, 9, 4, 8, 2, 3, 8, 10, 8, 3, 4]

    gestures = 12
    icons_positions = [0] * (n + 1)

    for i in range(0, len(icons)):
        icons_positions[icons[i]] = i

    for icon in icons_for_launch_positions:
        gestures += (icons_positions[icon] // k)

        if icons_positions[icon] != 0:
            previous_icon = icons[icons_positions[icon] - 1]

            swap(icons, icons_positions[icon], icons_positions[previous_icon])
            swap(icons_positions, icon, previous_icon)

    print(gestures)


def swap(collection_list, first_index, second_index):
    temp = collection_list[first_index]
    collection_list[first_index] = collection_list[second_index]
    collection_list[second_index] = temp


if __name__ == '__main__':
    main()
